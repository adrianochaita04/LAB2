.PHONY: clean
CC=gcc
CFLAGS=-g -Wall

programa: programaprincipal.o sumar.o restar.o multiplicar.o dividir.o
	$(CC) $(CFLAGS) programaprincipal.o sumar.o restar.o multiplicar.o dividir.o -o programa

principal.o: programaprincipal.c funciones.h
	$(CC) $(CFLAGS) -c principal.c -o principal.o

sumar.o: sumar.c funciones.h
	$(CC) $(CFLAGS) -c sumar.c -o sumar.o

restar.o: restar.c funciones.h
	$(CC) $(CFLAGS) -c restar.c -o restar.o

multiplicar.o: multiplicar.c funciones.h
	$(CC) $(CFLAGS) -c multiplicar.c -o multiplicar.o

dividir.o: dividir.c funciones.h
	$(CC) $(CFLAGS) -c dividir.c -o dividir.o

clean:
	rm -rf *.o programa
