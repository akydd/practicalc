CC=gcc
CFLAGS=-Wall -ansi -pedantic -ggdb

OBJS=bstree.o 4.o

4: $(OBJS)
	$(CC) $(CFLAGS) -o 4 $(OBJS)

bstree.o:bstree.c bstree.h
4.o:4.c bstree.h
