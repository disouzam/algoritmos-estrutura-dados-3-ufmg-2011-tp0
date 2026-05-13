#include <stdio.h>
#include <stdlib.h>

#include "digit.h"
#include "list.h"

int main()
{
	#if 0
	printf("==Teste dos construtor, destrutor e outras funções do TAD digit==\n\n");
	
	DIGITptr d;
	
	d = create_digit();
	printf("d vale %p\n", d);
	
	set_dig(d,8);
	print_info(d);
	
	destruir_digit(&d);
	print_info(d);
	
	#endif
	
	
	#if 1
	printf("==Teste dos construtor, destrutor e outras funções do TAD list==\n\n");
	LISTptr l;
	l = create_list();
	
	int i;
	
	for (i = 1; i <= 3; i++)
	{
		insert_end(l,i);
	}
	
	print_list (l,0);
	
	long int s = get_size(l);
	
	while (s != 0)
	{
		printf("Valor de s em main:%ld", s);
		char c[1];
		scanf("%c", c);
		DIGITptr temp;
		temp = get_last(l);
		erase_digit(&l , &temp);
		print_list(l,0);
		s = get_size(l);
	}
	printf("Teste terminado\n");
	#endif
	
	#if 0
	LISTptr l2;
	
	l2 = create_list();
	
	DIGITptr d2;
	
	d2 = create_digit();
	
	print_info(d2);
	
	set_first(l2,d2);
	
	print_info(get_first(l2));
	
	set_dig(get_first(l2),5);
	
	destruir_digit(&d2);
	
	print_info(get_first(l2));
	
	
	#endif
	return 0;
}
