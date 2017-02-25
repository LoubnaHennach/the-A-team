

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g 
LDFLAGS=-lm -lcunit 

all: lotA

unit_test.o : unit_test.c unit_test.h grid_color.h
	${CC} ${CFLAGS} -c unit_test.c

grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

main.o: main.c  grid_color.h unit_test.h
	${CC} ${CFLAGS} -c main.c

lotA: grid_color.o main.o unit_test.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
	
doc: doxygen Doxyfile

valgrind: valgrind --leak-check=yes ./lotA

clean:
	rm grid_color.o main.o
