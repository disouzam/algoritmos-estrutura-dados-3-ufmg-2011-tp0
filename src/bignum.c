#include "bignum.h"

struct bignum
{
	LIST* list_num;
	char sign;
}; // struct bignum

//Construtor para o struct bignum
BIGNUM* criar()
{
	BIGNUM* b;
	
	b = (BIGNUM*) malloc (sizeof(struct bignum));
	
	if (b != NULL)
	{
		LIST* l;
		
		l = create_list();
		b->list_num = l;
		clear_list(l);
		b->sign = 1;
	}
	else
	{
		printf("\nProblema ao alocar memória para uma variável bignum\n.");
	}
	return (b);
} //BIGNUM* criar()

//Destrutor para o TAD bignum;
void destruir(BIGNUM** b)
{
	destruir_list(&((*b)->list_num));
	free(*b);
	*b = NULL;
} //void destruir(BIGNUM** b)

//Rotina para ler uma variável BIGNUM a partir do prompt do console
void ler_tela(BIGNUM* b)
{
	clear_list(b->list_num);
	printf("\nb->list_num %p\n", b->list_num);
	
	printf("\nLeitura de número para o TAD bignum\n");
	printf("O caractere delimitador do término é caractere nova linha:\n");
	
	int c;
	
	c = getchar();
	
	if (c == 45)
	{
		b->sign = -1;
	}else
	{
		b->sign = 1;
		if ((c > 48) && (c <= 57))
		{
			insert_end(b->list_num, c % 48);
		}
	}
	
	c = getchar();
	while((c >= 48) && (c <= 57))
	{
		insert_end(b->list_num, c % 48);
		c = getchar();
	}
	
	printf("\n\nbignum lido = ");
	print_list(b->list_num, 1);
	return;
} //void ler_tela(BIGNUM* b)

//Determina qual número é maior. 
//Retorna 1 se A > B
//Retorna 0 se A < B
int maior(BIGNUM* A, BIGNUM* B)
{
	if (get_size(A->list_num) > get_size(B->list_num))
	{
		return (1);
	}
	else
	{
		if ((get_size(A->list_num) < get_size(B->list_num)))
		{
			return (0);
		}
		else
		{
			DIGIT* a = get_first(A->list_num);
			DIGIT* b = get_first(B->list_num);
			
			while ((get_next(a) != NULL) && (get_dig(a) == get_dig(b)))
			{
				a = get_next(a);
				b = get_next(b);
			}
			
			if (get_dig(a) > get_dig(b))
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
	}
} //int maior(BIGNUM* A, BIGNUM* B)

//O valor do bignum B é somado ao valor do bignum A e o resultado fica armazenado em A
void somar(BIGNUM* A, BIGNUM* B)
{
	if (get_size(A->list_num) >= 1 && get_size(B->list_num) >= 1)
	{
		if (A->sign == B->sign)
		{
			DIGIT* a = get_last(A->list_num);
			DIGIT* b = get_last(B->list_num);
			
			if (get_size(A->list_num) >= get_size(B->list_num))
			{
				char f;
				char g;
				char h;
					
				while (b != NULL)
				{
					char a_dig = get_dig(a);
					char b_dig = get_dig(b);
					
					char c = a_dig + b_dig;
					char d = c % 10;
					char e = c / 10;
					
					set_dig(a , d);
					
					if (get_previous(a) != NULL)
					{
						f = get_dig(get_previous(a));
						f = f + e;
						g = f % 10;
						h = f / 10;
						
						set_dig(get_previous(a) , g);
					}
					else
					{
						if(e != 0)
						{
							insert_begin(A->list_num , e);
						}
					}
					
					a = get_previous(a);
					b = get_previous(b);
				}
				
				printf("\na%p",a);
				
				if (h != 0)
				{
					if (a != NULL)
					{
						while (a != NULL && h != 0)
						{
							f = get_dig(a);
							f = f + h;
							g = f % 10;
							h = f / 10;
							
							set_dig(a , g);
							
							if (get_previous(a) != NULL)
							{
								f = get_dig(get_previous(a));
								f = f + h;
								g = f % 10;
								h = f / 10;
								
								set_dig(get_previous(a) , g);
							}
							else
							{
								
								if (h != 0)
								{
									printf("\n\n\nDeu certo");
									insert_begin(A->list_num , h);
									h = 0;
								}
							}
							
							a = get_previous(a);
						}
					}
					else
					{
						printf("\n\n\nEntrou");
						insert_begin(A->list_num , h);
					}
				}
			}
			else
			{
				/*while (b != NULL)
				{
					a_dig = get_dig(a);
					b_dig = get_dig(b);
					
					char c = a_dig + b_dig;
					char d = c % 10;
					char e = c / 10;
					
					
					a = get_previous(a);
					b = get_previous(b);
				}*/
			}
			//while ()
			
		}
		else
		{
			
		}
	}
	else
	{
		printf("Erro: Problema na função somar do TAD bignum\n");
		printf("Os dois argumentos devem possuir no mínimo 1 dígito para a função executar.\n");
	}
	
}

// Imprime o número armazenado em bignum na tela usando o ponto como separador de milhar. 
// Números gigantes podem requerer a impressão em múltiplas linhas.
// O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
// sci = 0                                        -> Não imprime a notação científica ao final.
// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
void imprimir(BIGNUM* A, char sci)
{
	if((A->sign) == -1)
	{
		printf("-");
	}
	print_list(A->list_num, sci);
}


//Função de manutenção do TAD bignum. Verifica o bom funcionamento de suas funções.
void debug_bignum()
{
	printf ("\nTeste e depuração do TAD bignum\n");
	
	BIGNUM* b = criar();
	printf("\nTeste do construtor\n");
	printf("Endereço de b = %p\n", &b);
	printf("Ponteiro b para bignum = %p\n", b);
	destruir(&(b));
	printf("\nTeste do destrutor\n");
	printf("Endereço de b = %p\n", &b);
	printf("Ponteiro b para bignum = %p\n", b);
	
	BIGNUM* c = criar();
	ler_tela(c);
	
	BIGNUM* d = criar();
	ler_tela(d);
	
	if (maior(c,d) == 1)
	{
		printf("\nPrimeiro número é maior\n");
	}
	else
	{
		printf("\nSegundo número é maior\n");
	}
	
	printf("\nTeste da função somar\n");
	char ans = 's';
	char* ans_ptr = &ans;
	
	
	while (ans == 's')
	{
		ler_tela(c);
		ler_tela(d);
		somar(c , d);
		printf ("\nResultado c + d = ");
		print_list(c->list_num, 1);
		printf("\nDeseja repetir o teste? (s/n)");
		scanf("%s", ans_ptr);
	}
	
	destruir(&c);
	destruir(&d);
}
