#include "digit.h"

struct digit
{
	char dig_;
	DIGIT* previous_;
	DIGIT* next_;
}; //struct digit

//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
DIGIT* create_digit ()
{
	DIGIT* d;
	d = (DIGIT*) malloc(sizeof(struct digit));
	
	if (d != NULL)
	{
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
void destruir_digit (DIGIT** f)
{
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


//Função de manutenção do TAD digit. Verifica o bom funcionamento de suas funções.
void debug_digit()
{
	int x = 0;
	
	printf("\nExecução de testes para debug do TAD digit\n");
	
	//Teste do construtor
	printf("\nTestes do construtor\n");
	
	DIGIT* t = NULL;
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	printf("t = %p\n", t);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	t = create_digit();
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	if (t != NULL)
	{
		printf("Alocação bem sucedida\n");
		printf("t = %p\n", t);
		printf("t->dig_ = %d\n", t->dig_);
		printf("t->previous_ = %p\n", t->previous_);
		printf("t->next_ = %p\n", t->next_);
	}
	else
	{
		x++;
		printf("Problema na alocação de memória\n");
		printf("t = %p\n", t);
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste do set_dig
	printf("\nTeste de set_dig\n");
	
	set_dig(t , 15);
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	if (t->dig_ == 15)
	{
		printf("Alteração do dígito bem sucedida\n");
		printf("t = %p\n", t);
		printf("t->dig_ = %d\n", t->dig_);
		printf("t->previous_ = %p\n", t->previous_);
		printf("t->next_ = %p\n", t->next_);
	}
	else
	{
		x++;
		printf("Problema na função set_dig\n");
		printf("t = %p\n", t);
		printf("t->dig_ = %d\n", t->dig_);
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste do set_previous
	printf("\nTeste de set_previous\n");
	
	DIGIT* u = create_digit();
	
	set_previous(t , u);
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	if (t->previous_ == u)
	{
		printf("Alteração do ponteiro previous_ bem sucedida\n");
		printf("t = %p\n", t);
		printf("t->dig_ = %d\n", t->dig_);
		printf("u = %p\n", u);
		printf("t->previous_ = %p\n", t->previous_);
		printf("t->next_ = %p\n", t->next_);
	}
	else
	{
		x++;
		printf("Problema na função set_previous\n");
		printf("t = %p\n", t);
		printf("u = %p\n", u);
		printf("t->previous_ = %p\n", t->previous_);
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste do set_next
	printf("\nTeste de set_next\n");
	
	DIGIT* v = create_digit();
	
	set_next(t , v);
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	if (t->next_ == v)
	{
		printf("Alteração do ponteiro next_ bem sucedida\n");
		printf("t = %p\n", t);
		printf("t->dig_ = %d\n", t->dig_);
		printf("t->previous_ = %p\n", t->previous_);
		printf("v = %p\n", v);
		printf("t->next_ = %p\n", t->next_);
	}
	else
	{
		x++;
		printf("Problema na função set_next\n");
		printf("t = %p\n", t);
		printf("v = %p\n", v);
		printf("t->next_ = %p\n", t->next_);
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste do destrutor
	printf("\nTeste do destrutor\n");
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	printf("Ponteiros existentes:\n");
	printf("t = %p\n", t);
	printf("u = %p\n", u);
	printf("v = %p\n", v);
	
	destruir_digit(&t);
	if (t == NULL) 
	{
		printf("\nDestruição bem sucedida\n");
	}
	else
	{
		x++;
		printf("\nFalha na destruição\n");
	}
	printf("t destruído = %p\n", t);
	
	destruir_digit(&u);
	if (u == NULL) 
	{
		printf("\nDestruição bem sucedida\n");
	}
	else
	{
		x++;
		printf("\nFalha na destruição\n");
	}
	printf("u destruído = %p\n", u);
	
	destruir_digit(&v);
	if (v == NULL) 
	{
		printf("\nDestruição bem sucedida\n");
	}
	else
	{
		x++;
		printf("\nFalha na destruição\n");
	}
	printf("v destruído = %p\n", v);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_dig
	printf("\nTeste de get_dig\n");
	
	DIGIT* a = create_digit();
	set_dig(a,12);
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	char c = get_dig(a);
	if (c == 12)
	{
		printf("Função acesso get_dig correta\n");
	}
	else
	{
		x++;
		printf("Erro na função get_dig\n");
	}
	printf("get_dig(a) = %d\n", get_dig(a));
	printf("c = get_dig(a) = %d\n", c);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_previous
	printf("\nTeste de get_previous\n");
	
	DIGIT* f = create_digit();
	DIGIT* g = create_digit();
	set_previous(f,g);
	g = NULL;
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	g = get_previous(f);
	if (g == get_previous(f))
	{
		printf("Função acesso get_previous correta\n");
	}
	else
	{
		x++;
		printf("Erro na função get_previous\n");
	}
	printf("get_previous(f) = %p\n", get_previous(f));
	printf("g = get_previous(f) = %p\n", g);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_next
	printf("\nTeste de get_next\n");
	
	DIGIT* h = create_digit();
	DIGIT* i = create_digit();
	set_next(h,i);
	i = NULL;
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	i = get_next(h);
	if (i == get_next(h))
	{
		printf("Função acesso get_next correta\n");
	}
	else
	{
		x++;
		printf("Erro na função get_next\n");
	}
	printf("get_next(h) = %p\n", get_next(h));
	printf("i = get_next(h) = %p\n", i);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Resultado final do teste
	if (x != 0)
	{
		if (x == 1) printf("\n\nOcorreu 1 falha no TAD digit\n");
		if (x >= 2) printf("\n\nOcorreram %d falhas no TAD digit\n", x);
		printf("Verifique mensagens acima para correção\n");
	}
	else
	{
		printf("\n\nTodos os testes de funcionamento do TAD digit foram bem sucedidos\n");
		printf("As funções do TAD cumprem os requisitos estabelecidos no arquivo digit.h\n");
	}
} //void debug_digit()
