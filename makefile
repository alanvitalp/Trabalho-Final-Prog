ALL: main

main: main.o abb.o listaDupla.o vetor.o
	gcc -o main abb.o listaDupla.o vetor.o main.o

main.o: main.c
	gcc -c main.c

abb.o: abb.c abb.h
	gcc -c abb.c

lista.o: listaDupla.c listaDupla.h
	gcc -c listaDupla.c

vetor.o: vetor.c vetor.h
	gcc -c vetor.c

clean:
	rm -f *.0 main