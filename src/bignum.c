/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD bignum: implementação                         */
/*                                                   */
/*****************************************************/

#include "bignum.h"

//Funções auxiliares. Não fazem parte da interface do TAD
void subtrair_aux(BIGNUM* A, BIGNUM* B);

void multiplicar_aux(BIGNUM* A, BIGNUM* B);

void dividir_aux(BIGNUM* A, BIGNUM* B);

//Retorna 1 se A for igual a 1
//Retorna 0 se A for diferente de 1
int unitario(BIGNUM* A);



//Construtor para o struct bignum
BIGNUM* criar()
{
	BIGNUM* b;
	//Teste alocação dinâmica de memória
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
	
	char c;
	c = getchar();
	
	while (c == ' ' || c == '\n')
	{
		c = getchar();
	}
	
	if (c == '-')
	{
		b->sign = -1;
	}
	else
	{
		b->sign = 1;
		
		if ((c >= '0') && (c <= '9'))
		{
			insert_end(b->list_num, c % 48);
		}
	}
	
	c = getchar();
	
	while((c >= '0') && (c <= '9'))
	{
		insert_end(b->list_num, c % 48);
		c = getchar();
	}
	
	return;
} //void ler_tela(BIGNUM* b)


//Escreve o valor armazenado em b em um arquivo apontado por outfile
void escrever_texto(FILE* outfile, BIGNUM* b)
{
	DIGIT* iter = get_first(b->list_num);
	
	while (iter != NULL)
	{
		char iter_dig = get_dig(iter);
		
		iter_dig = iter_dig + 48;
		putc(iter_dig , outfile);
		iter = get_next(iter);
	}
	putc(EOF, outfile);
	
	return;
}

//Ler um número localizado em um arquivo texto
void ler_texto(FILE* infile, BIGNUM* b)
{
	clear_list(b->list_num);
	int ch;
	
	ch = getc(infile);
	
	while (ch != ' ' && ch != '\n')
	{
		insert_end(b->list_num , ch % 48);
		ch = getc(infile);
	}
	printf("\nNúmero lido do arquivo:");
	imprimir(b , 0);
	
	return;
}

// Copia o número armazenado em B para o número A
void copiar(BIGNUM* A, BIGNUM *B)
{
	clear_list(A->list_num);
	A->sign = B->sign;
	
	DIGIT* b = get_first(B->list_num);
	
	while (b != NULL)
	{
		insert_end(A->list_num, get_dig(b));
		b = get_next(b);
	}
}

//Determina qual módulo é maior. 
//Retorna 1 se |A| >= |B|
//Retorna 0 se |A| < |B|
int maior_modulo(BIGNUM* A, BIGNUM* B)
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
			
			if (get_dig(a) >= get_dig(b))
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
	}
} //int maior_modulo(BIGNUM* A, BIGNUM* B)

//O valor do bignum B é somado ao valor do bignum A e o resultado fica armazenado em A
void somar(BIGNUM* A, BIGNUM* B)
{
	if (get_size(A->list_num) >= 1 && get_size(B->list_num) >= 1)
	{
		if (A->sign == B->sign)
		{
			DIGIT* a = get_last(A->list_num);
			DIGIT* b = get_last(B->list_num);
			
			char a_dig = 0;
			char b_dig = 0;
			
			char c = 0;
			char d = 0;
			char e = 0;
			
			if (get_size(A->list_num) >= get_size(B->list_num))
			{
				while (b != NULL)
				{
					a_dig = get_dig(a);
					b_dig = get_dig(b);
					
					c = a_dig + b_dig + e;
					d = c % 10;
					e = c / 10;
					
					set_dig(a , d);
					
					a = get_previous(a);
					b = get_previous(b);
				}
				
				while (a != NULL)
				{
					a_dig = get_dig(a);
					c = a_dig + e;
					d = c % 10;
					e = c / 10;
					
					set_dig(a , d);
					
					a = get_previous(a);
				}
				
				if (e != 0)
				{
					insert_begin(A->list_num , e);
				}
			}
			else
			{
				char a_dig = 0;
				char b_dig = 0;
				
				char c = 0;
				char d = 0;
				char e = 0;
					
				while (a != NULL)
				{
					a_dig = get_dig(a);
					b_dig = get_dig(b);
					
					c = a_dig + b_dig + e;
					d = c % 10;
					e = c / 10;
					
					set_dig(a , d);
					
					a = get_previous(a);
					b = get_previous(b);
				}
				
				while (b != NULL)
				{
					b_dig = get_dig(b);
					c = b_dig + e;
					d = c % 10;
					e = c / 10;
					
					insert_begin(A->list_num , d);
					
					b = get_previous(b);
				}
				
				if (e != 0)
				{
					insert_begin(A->list_num , e);
				}
			}
		}
		else
		{
			BIGNUM* C = criar();
			copiar(C , B);
			
			int m = maior_modulo(A , C);
			
			if (m == 1)
			{
				subtrair_aux(A, C);
			}
			else
			{
				subtrair_aux(C, A);
				copiar(A , C);
			}
		
			destruir(&C);
		}
	}
	else
	{
		printf("Erro: Problema na função somar do TAD bignum\n");
		printf("Os dois argumentos devem possuir no mínimo 1 dígito para a função executar.\n");
	}
} //void somar(BIGNUM* A, BIGNUM* B)

//Realiza a subtração A - B e armazena o resultado obtido em A. B não é alterado.
void subtrair(BIGNUM* A, BIGNUM* B)
{
	BIGNUM* C = criar();
	copiar(C , B);
	
	if (A->sign != C->sign)
	{
		negativo(C);
		somar(A , C);
	}
	else
	{
		int m = maior_modulo(A , C);
		
		if (m == 1)
		{
			subtrair_aux(A , C);
		}
		else
		{
			subtrair_aux(C , A);
			copiar(A , C);
			A->sign = -(A->sign);
		}
	}
 	destruir(&C);
	return;
} //void subtrair(BIGNUM* A, BIGNUM* B)

// Imprime o número armazenado em bignum na tela usando o ponto como separador de milhar. 
// Números gigantes podem requerer a impressão em múltiplas linhas.
// O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
// sci = 0                                        -> Não imprime a notação científica ao final.
// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
void imprimir(BIGNUM* A, char sci)
{
	unsigned long int s = get_size(A->list_num);
	
	if((A->sign) == -1)
	{
		printf("-");
	}
	print_list(A->list_num);
	
	DIGIT* temp = get_first(A->list_num);
	
	if (sci == 1)
	{
		printf("   Notação científica: ");
		
		if (A->sign == -1)
		{
			printf("-");
		}
		printf("%d.", get_dig(temp));
		
		if (s == 1)
		{
			printf("00E0 ");
		}
		else
		{
			if (s == 2)
			{
				temp = get_next(temp);
				printf("%d0E1 ",get_dig(temp));
			}
			else
			{
				temp = get_next(temp);
				printf("%d",get_dig(temp));
				temp = get_next(temp);
				printf("%dE%ld",get_dig(temp), s - 1);
			}
		}
	}
	return;
}

// Altera o sinal de A, fazendo A = -A
void negativo (BIGNUM* A)
{
	A->sign = -(A->sign);
	return;
}


// Realiza a subtração A - B e armazena o resultado obtido em A. B não é alterado. 
// Os sinais não são considerados na operação e |A| >= |B|.
// A operação executada é sign(A) * (|A| - |B|)
void subtrair_aux(BIGNUM* A, BIGNUM* B)
{
	DIGIT* a = get_last(A->list_num);
	DIGIT* b = get_last(B->list_num);
	
	char a_dig = 0;
	char b_dig = 0;
	
	char c = 0;
	char d = 0;
	
	while (b != NULL)
	{
		a_dig = get_dig(a);
		b_dig = get_dig(b);
		
		if (d == 1)
		{
			if (a_dig == 0)
			{
				a_dig = 9;
			}else
			{
				a_dig = a_dig - 1;
				d = 0;
			}
		}
		
		if (a_dig >= b_dig)
		{
			c = a_dig - b_dig;
		}
		else
		{
			c = (10 + a_dig) - b_dig - d;
			d = 1;
		}
		
		set_dig(a , c);
		
		a = get_previous(a);
		b = get_previous(b);
	}
	
	while (a != NULL && d == 1)
	{
		a_dig = get_dig(a);
		
		if (a_dig == 0)
		{
			a_dig = 9;
		}else
		{
			a_dig = a_dig - 1;
			d = 0;
		}
		
		set_dig(a , a_dig);
		a = get_previous(a);
	}
	
	a = get_first(A->list_num);
	a_dig = get_dig(a);
	
	while ((get_size(A->list_num) > 1) && (a_dig == 0))
	{
		DIGIT* temp = get_next(a);
		erase_digit(A->list_num, &a);
		a = temp;
		a_dig = get_dig(a);
	}
	return;
	
}

// Multiplica o número A pelo número B e armazena o resultado em A
void multiplicar(BIGNUM* A, BIGNUM* B)
{
	unsigned long int size_a = get_size(A->list_num);
	unsigned long int size_b = get_size(B->list_num);
	
	char a_dig = get_dig(get_first(A->list_num));
	char b_dig = get_dig(get_first(B->list_num));
	
	if (((size_a == 1) && (a_dig == 0 || a_dig == 1)) || ((size_b == 1) && (b_dig == 0 || b_dig == 1)))
	{
		if ((size_a == 1 && a_dig == 0) || (size_b == 1 && b_dig == 0))
		{
			clear_list(A->list_num);
			A->sign = 1;
			insert_begin(A->list_num, 0);
		}
		
		if ((size_a == 1 && a_dig == 1) || (size_b == 1 && b_dig == 1))
		{
			if (size_a == 1 && a_dig == 1)
			{
				char s = (A->sign) * (B->sign);
				copiar(A , B);
				A->sign = s;
			}
		}
	}
	else
	{
		char s = (A->sign) * (B->sign);
		
		int m = maior_modulo(A, B);
		
		BIGNUM* temp = criar();
		
		if (m == 0)
		{
			copiar(temp, B);
			multiplicar_aux(temp, A);
		}
		else
		{
			copiar(temp , A);
			multiplicar_aux(temp, B);
		}
		copiar(A, temp);
		
		A->sign = s;
		
		destruir(&temp);
	}
	return;
}

// Função auxiliar para executar a multiplicação.
// Os sinais dos operandos não são alterados nem considerados nessa função.
// Seu comportamento equivale a obter o módulo do produto e armazenar em A
// A alteração do sinal na função multiplicar.
// Nessa função A deve ser maior ou igual a B (os seus respectivos módulos) : |A| >= |B|
void multiplicar_aux(BIGNUM* A, BIGNUM* B)
{
	BIGNUM* ACUM = criar();
	insert_end(ACUM->list_num , 0);
	
	BIGNUM* TRANSIT = criar();
	
	DIGIT* b = get_last(B->list_num);
	
	char a_dig = 0;
	char b_dig = 0; 
	
	unsigned long int i = 0;
	
	while (b != NULL)
	{
		DIGIT* a = get_last(A->list_num);
		clear_list(TRANSIT->list_num);
		
		b_dig = get_dig(b);
		
		char d = 0;
		char e = 0;
		char f = 0;
		
		while(a != NULL)
		{
			a_dig = get_dig(a);
			
			d = a_dig * b_dig + f;
			e = d % 10;
			f = d / 10;
			
			insert_begin(TRANSIT->list_num , e);
			
			a = get_previous(a);
		}
		
		if (f != 0)
		{
			insert_begin(TRANSIT->list_num , f);
		}
		
		unsigned long int j;
		for (j = 0; j < i; j++)
		{
			insert_end(TRANSIT->list_num, 0);
		}
		
		somar(ACUM, TRANSIT);
		b = get_previous(b);
		i++;
	}
	copiar(A , ACUM);
	
	destruir(&ACUM);
	destruir(&TRANSIT);
	return;
}



void long_to_big(BIGNUM* A, unsigned long int b)
{
	clear_list(A->list_num);
	
	if (b >= 0)
	{
		A->sign = 1;
	}
	else
	{
		A->sign = -1;
		b = -b;
	}
	unsigned long int c;
	
	while (b >= 10)
	{
		c = b % 10;
		insert_begin(A->list_num, c);
		b = b / 10;
	}
	
	insert_begin(A->list_num, b);
}

// Operação de divisão inteira A / B. 
// A >= 0 e B >0
// Se A >= B, o resultado, armazenado na variável A, 
// é o maior inteiro que multiplicado por B resulta em um número menor ou igual a A
// Se A < B, o resultado é igual a 0.
void dividir(BIGNUM* A, BIGNUM* B)
{
	int m = maior_modulo(A , B);
	
	if (m == 0)
	{
		clear_list(A->list_num);
		A->sign = 1;
		
		insert_begin(A->list_num , 0);
	}
	else
	{
		dividir_aux(A , B);
	}
}

//Função auxiliar para executar a divisão
void dividir_aux(BIGNUM* A, BIGNUM* B)
{
	unsigned long int size_a = get_size(A->list_num);
	unsigned long int size_b = get_size(B->list_num);
	
	unsigned long int order, j;
	
	order = size_a - size_b;
	
	if (order != 0)
	{
		order = order - 1;
	}
	
	BIGNUM* FATOR = criar();
	insert_begin(FATOR->list_num, 1);
	
	BIGNUM* INCREMENT = criar();
	
	for (j = 0; j < order; j++)
	{
		insert_end(FATOR->list_num , 0);
	}
	
	copiar(INCREMENT, FATOR);
	
	BIGNUM* PRODUTO = criar();
	
	int m;
	
	BIGNUM* UNIDADE = criar();
	insert_begin(UNIDADE->list_num , 1);
	
	int f = igual(INCREMENT , UNIDADE);
	
	while (f == 0)
	{
		somar(FATOR, INCREMENT);
		copiar(PRODUTO, FATOR);
		multiplicar(PRODUTO, B);
		
		m = maior_modulo(PRODUTO, A);
		if (m == 1)
		{
			subtrair(FATOR, INCREMENT);
			if (get_size(INCREMENT->list_num) > 1)
			{
				DIGIT* inc = get_last(INCREMENT->list_num);
				erase_digit(INCREMENT->list_num , &inc);
			}
		}
		
		f = igual(INCREMENT , UNIDADE);
	}
	
	BIGNUM* PRODUTO2 = criar();
	
	copiar(PRODUTO, FATOR);
	multiplicar(PRODUTO, B);
	somar(FATOR , INCREMENT);
	copiar(PRODUTO2, FATOR);
	multiplicar(PRODUTO2, B);
	
	int p1, p2;
	p1 = maior_modulo(PRODUTO , A);
	p2 = maior_modulo(PRODUTO2 , A);
	
	while ((p1 + p2) == 0)
	{
		copiar(PRODUTO, PRODUTO2);
		somar(FATOR , INCREMENT);
		copiar(PRODUTO2, FATOR);
		multiplicar(PRODUTO2, B);
		
		
		p1 = maior_modulo(PRODUTO , A);
		p2 = maior_modulo(PRODUTO2 , A);
	}
	
	f = igual (PRODUTO2, A);
	if (f == 0)
	{
		subtrair (FATOR, INCREMENT);
	}
	copiar (A , FATOR);
}




//Função para verificar igual entre A e B
// Se A == B, retorna 1;
// Se A != B, retorna 0;
int igual (BIGNUM* A, BIGNUM* B)
{
	unsigned long int size_a = get_size(A->list_num);
	unsigned long int size_b = get_size(B->list_num);
	
	if (size_a == size_b)
	{
		int sign_a = A->sign;
		int sign_b = B->sign;
		
		if (sign_a == sign_b)
		{
			DIGIT* a = get_first(A->list_num);
			DIGIT* b = get_first(B->list_num);
			
			char a_dig = get_dig(a);
			char b_dig = get_dig(b);
			
			while ((get_next(a) != NULL) && (a_dig == b_dig))
			{
				a = get_next(a);
				b = get_next(b);
				a_dig = get_dig(a);
				b_dig = get_dig(b);
			}
			
			if (a_dig == b_dig)
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
		else
		{
			return (0);
		}
		
	}
	else
	{
		return (0);
	}
}

//Retorna 1 se A for igual a 1
//Retorna 0 se A for diferente de 1
int unitario(BIGNUM* A)
{
	unsigned long int size_a = get_size(A->list_num);
	
	if (size_a == 1 && get_dig(get_first(A->list_num)) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Retorna 1 se A for igual a 0
//Retorna 0 se A for não nulo
int nulo(BIGNUM* A)
{
	unsigned long int size_a = get_size(A->list_num);
	
	if (size_a == 1 && get_dig(get_first(A->list_num)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Função fatorial
// Se A = 0 ou A = 1, retorna 1
// Caso contrário procede ao cálculo iterativo
void fatorial(BIGNUM* A)
{
	if (nulo(A) == 1 || unitario(A) == 1)
	{
		set_dig(get_first(A->list_num) , 1);
	}
	else
	{
		BIGNUM* iter = criar();
		BIGNUM* UNIDADE = criar();
		
		insert_begin(UNIDADE->list_num , 1);
		copiar(iter , A);
		
		subtrair(iter, UNIDADE);
		
		do
		{
			multiplicar(A, iter);
			subtrair(iter, UNIDADE);
		}while (maior_modulo(iter , UNIDADE) == 1);
		
		destruir(&iter);
		destruir(&UNIDADE);
	}
	return;
}

// Calcula a combinação entre dois números.
// Combinação (A, B) = fatorial (A) / (fatorial (B) * fatorial (A - B))
// A e B maiores que zero. A > B
void combinacao(BIGNUM* A, BIGNUM* B)
{
	int n_a = nulo(A);
	int n_b = nulo(B);
	
	if (n_a != 1 && n_b != 1)
	{
		int i = igual(A, B);
		if (i == 1)
		{
			clear_list(A->list_num);
			insert_begin(A->list_num , 1);
		}
		else
		{
			BIGNUM* temp = criar();
			BIGNUM* iter = criar();
			BIGNUM* UNIDADE = criar();
			insert_begin(UNIDADE->list_num , 1);
			
			copiar(temp , A);
			subtrair(temp , B);
			
			if ((maior_modulo(temp , B) == 1))
			{
				copiar(iter , A);
				subtrair(iter, UNIDADE);
				
				while (igual(iter, temp) != 1)
				{
					multiplicar(A, iter);
					subtrair(iter, UNIDADE);
				}
				
				copiar(temp, B);
				fatorial(temp);
				dividir(A , temp);
				
			}
			else
			{
				copiar(iter , A);
				subtrair(iter, UNIDADE);
				
				while (igual(iter, B) != 1)
				{
					multiplicar(A, iter);
					subtrair(iter, UNIDADE);
				}
				
				fatorial(temp);
				dividir(A , temp);
			}
			
			destruir(&UNIDADE);
			destruir(&iter);
			destruir(&temp);
		}
	}
	else
	{
		if (n_a == 1 && n_b == 1)
		{
			clear_list(A->list_num);
			insert_begin(A->list_num , 1);
		}
		else
		{
			if (n_b == 1)
			{
				clear_list(A->list_num);
				insert_begin(A->list_num , 1);
			}
		}
	}
	return;
}
