# ------------------------------ makefile para la AC1 ------------------------
# Programa:		makefile
# Descripción:		EX1 LlistaBIDord
# Autor:			David Seguí
# Fecha ult. modifcación: 07/10/2018
# Makefile utilizado para el testeo de la Lista ordenada bidireccional creada
# que se encuentra en el fichero main.c, el fichero LlistaBIDord contiene la Lista

# ordenada bidireccional y el .h contiene los headers de las fucniones.
all: AC1

#	compila el modulo .c de la lista y el .h de esta
main.o:	main.c LlistaBIDord.c LlistaBIDord.h
	gcc main.c -c -Wall -Wextra

#	compila el modulo .c de la lista y el .h de esta
LlistaBIDord.o:	LlistaBIDord.c LlistaBIDord.h
	gcc LlistaBIDord.c -c -Wall -Wextra

# compila el modulo main del programa junto al .o i crea el ejecutable
AC1: main.o LlistaBIDord.o
	gcc main.o LlistaBIDord.o -o AC1.exe -Wall -Wextra

# Comando del makefile que elimina el ejecutable i todos los .o
clean:
	rm *.o AC1.exe
