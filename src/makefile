all:tp0

tp0: main.o digit.o list.o bignum.o
	
	gcc -o tp0 main.o digit.o list.o bignum.o



main.o: main.c
	
	gcc -Wall -c -o main.o main.c



digit.o: digit.c digit.h

	gcc -Wall -c -o digit.o digit.c



list.o: list.c digit.h list.h

	gcc -Wall -c -o list.o list.c



bignum.o: bignum.c bignum.h digit.h list.h

	gcc -Wall -c -o bignum.o bignum.c
