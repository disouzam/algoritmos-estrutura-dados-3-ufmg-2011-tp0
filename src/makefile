all:tp0

tp0: main.o digit.o list.o
	gcc -o tp0 main.o digit.o list.o

main.o: main.c
	gcc -Wall -c -o main.o main.c

digit.o: digit.c
	gcc -Wall -c -o digit.o digit.c

list.o: list.c
	gcc -Wall -c -o list.o list.c

list.o: digit.h
