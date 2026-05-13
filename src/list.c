#include "list.h"

struct list
{
	DIGIT* first_;
	DIGIT* last_;
	unsigned long int size_;
}; //struct list

//Construtor: Aloca memória para o struct list e retorna o ponteiro para um list vazio.
LIST* create_list ()
{
	LIST* l;
	
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

//Insere um dígito no início da lista encadeada.
void insert_begin(LIST* l, char d)
{
	if (l != NULL)
	{
		unsigned long int s = get_size(l);
		set_size(l , s + 1);
		
		DIGIT* new_digit = NULL;
		new_digit = create_digit();
		
		if (new_digit == NULL)
		{
			printf("\n\nFalha ao alocar memória para um novo dígito na função insert_begin\n");
			printf("Tamanho atual do TAD list = %ld\n", get_size(l));
		}
		else
		{
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
		set_size(l , s + 1);
		
		DIGIT* new_digit;
		new_digit = create_digit();
		
		if (new_digit == NULL)
		{
			printf("\n\nFalha ao alocar memória para um novo dígito na função insert_begin\n");
			printf("Tamanho atual do TAD list = %ld\n", get_size(l));
		}
		else
		{
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

//Copia a lista A para a lista B. Todos os dados armazenados na lista B são perdidos. A lista A não é alterada.
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

//Função de manutenção do TAD list. Verifica o bom funcionamento de suas funções.
void debug_list()
{
	int x = 0;
	
	//Testes do construtor
	printf("Testes do construtor\n");
	LIST* l = NULL;
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	printf("l = %p\n", l);
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	l = create_list();
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	if (l != NULL)
	{
		printf("Alocação de lista bem sucedida\n");
		printf("l = %p\n", l);
		printf("l->first_ = %p\n", l->first_);
		printf("l->last_ = %p\n", l->last_);
		printf("l->size_ = %ld\n", l->size_);
	}
	else
	{
		x++;
		printf("Problema na alocação de memória\n");
		printf("l = %p\n", l);
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de set_first
	printf("\nTeste de set_first\n");
	
	DIGIT* d = create_digit();
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	printf("Endereço do primeiro dígito criado = %p\n", d);
	printf("l->first_ = %p\n",l->first_);
	
	set_first(l , d);
	printf("Após uso de set_first:   l->first_ = %p\n",l->first_);
	if (l->first_ == d)
	{
		printf("Alteração de first_ no struct list bem sucedida.\n");
	}
	else
	{
		x++;
		printf("Problema na função set_first\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de set_last
	printf("\nTeste de set_last\n");
	
	DIGIT* e = create_digit();
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	printf("Endereço do segundo dígito criado = %p\n", e);
	printf("l->last_ = %p\n",l->last_);
	
	set_last(l , e);
	printf("Após uso de set_last:   l->last_ = %p\n",l->last_);
	if (l->last_ == e)
	{
		printf("Alteração de last_ no struct list bem sucedida.\n");
	}
	else
	{
		x++;
		printf("Problema na função set_last\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de set_size
	printf("\nTeste de set_size\n");
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	set_size(l , 1);
	printf("Tamanho ajustado para 1 - set_size(l,1). \nsize_ = %ld\n", l->size_);
	set_size(l , 2);
	printf("Tamanho ajustado para 2 - set_size(l,2). \nsize_ = %ld\n", l->size_);
	set_size(l , 3);
	printf("Tamanho ajustado para 3 - set_size(l,3). \nsize_ = %ld\n", l->size_);
	
	if (l->size_ == 3)
	{
		printf("Alteração de size_ no struct list bem sucedida.\n");
	}
	else
	{
		x++;
		printf("Problema na função set_size\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_first
	printf("\nTeste de get_first\n");
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	
	if (l->first_ == get_first(l))
	{
		printf("Função get_first funcionando corretamente.\n");
	}
	else
	{
		x++;
		printf("Problema na função get_first\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_last
	printf("\nTeste de get_last\n");
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	
	if (l->last_ == get_last(l))
	{
		printf("Função get_last funcionando corretamente.\n");
	}
	else
	{
		x++;
		printf("Problema na função get_last\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste de get_size
	printf("\nTeste de get_size\n");
	
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	
	if (l->size_ == get_size(l))
	{
		printf("Função get_size funcionando corretamente.\n");
	}
	else
	{
		x++;
		printf("Problema na função get_size\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	
	//Teste das funções usando recursos próprios da lista: inserir, excluir, destruir e outros.
	//Para esse teste será criado uma nova lista new_list
	printf("\n\nTeste usando os recursos da lista como inserir dígito, excluir dígito e outras...\n");
	
	LIST* new_list = create_list();
	printf("\nNova lista criada\n");
	printf("new_list = %p\n", new_list);
	printf("get_first = %p\n", get_first(new_list));
	printf("get_last = %p\n", get_last(new_list));
	printf("get_size = %ld\n", get_size(new_list));
	
	printf("\nInserir um elemento no início de valor 8\n");
	insert_begin(new_list, 8);
	printf("Valor no primeiro dígito da lista: %d\n", get_dig(get_first(new_list)));
	printf("new_list = %p\n", new_list);
	printf("get_first = %p\n", get_first(new_list));
	printf("get_last = %p\n", get_last(new_list));
	printf("get_size = %ld\n", get_size(new_list));
	
	printf("\nInserir um elemento no início de valor 5\n");
	insert_begin(new_list, 5);
	printf("Valor no primeiro dígito da lista: %d\n", get_dig(get_first(new_list)));
	printf("new_list = %p\n", new_list);
	printf("get_first = %p\n", get_first(new_list));
	printf("get_last = %p\n", get_last(new_list));
	printf("get_size = %ld\n", get_size(new_list));
	
	printf("\nInserir um elemento no final de valor 3\n");
	insert_end(new_list, 3);
	printf("Valor no último dígito da lista: %d\n", get_dig(get_last(new_list)));
	printf("new_list = %p\n", new_list);
	printf("get_first = %p\n", get_first(new_list));
	printf("get_last = %p\n", get_last(new_list));
	printf("get_size = %ld\n", get_size(new_list));
	
		printf("\nInserir um elemento no final de valor 1\n");
	insert_end(new_list, 1);
	printf("Valor no último dígito da lista: %d\n", get_dig(get_last(new_list)));
	printf("new_list = %p\n", new_list);
	printf("get_first = %p\n", get_first(new_list));
	printf("get_last = %p\n", get_last(new_list));
	printf("get_size = %ld\n", get_size(new_list));
	
	print_list(new_list);
	
	//Teste do destrutor da lista
	printf("\nTeste do destrutor da lista\n");
	
	print_list(new_list);
	printf("new_list antes de destruir = %p\n", new_list);
	destruir_list(&new_list);
	printf("new_list após destruir = %p\n", new_list);
	print_list(new_list);
	printf("\n*********** MENSAGEM - início ***********\n"); //Começo da mensagem
	
	if (l != NULL)
	{
		printf("Destrutor funcionando corretamente.\n");
	}
	else
	{
		x++;
		printf("Problema ao liberar a memória com o destrutor.\n");
	}
	printf("=========== MENSAGEM - final  ===========\n"); //Fim da mensagem
	
	//Teste final
	
	LIST* new_list2 = create_list();
	//LIST* new_list3 = create_list();
	unsigned long int j;
	
	for(j = 0; j < 1000000; j++)
	{
		insert_begin(new_list2, j%10);
		//insert_begin(new_list3, j%3);
		if (j%100000 == 0)
		{
			printf("newlist2 - size = %ld\n", get_size(new_list2));
			print_list(new_list2);
			printf("\n\n");
			//print_list(new_list3, 1);
			//printf("\n Ponteiro antes de clear_list %p\n", new_list3);
			//clear_list(new_list3);
			//print_list(new_list3, 1);
			//printf("\n Ponteiro após clear list %p\n", new_list3);
			
			printf("\n\n======================Término==============================\n\n");
			
			char c = 0;
			while (c != '\n')
			{
				c = getchar();
			}
		}
		
	}
	
	//Resultado final do teste
	if (x != 0)
	{
		if (x == 1) printf("\n\nOcorreu 1 falha no TAD list\n");
		if (x >= 2) printf("\n\nOcorreram %d falhas no TAD list\n", x);
		printf("Verifique mensagens acima para correção\n");
	}
	else
	{
		printf("\n\nTodos os testes de funcionamento do TAD list foram bem sucedidos\n");
		printf("As funções do TAD cumprem os requisitos estabelecidos no arquivo list.h\n");
	}
} //void debug_list()
