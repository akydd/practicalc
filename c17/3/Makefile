CC=gcc
CFLAGS=-Wall -ansi -pedantic

OBJS=symbol_table.o 3.o

3:	$(OBJS)
	$(CC) $(CFLAGS) -o 3 $(OBJS)

symbol_table.o:symbol_table.c symbol_table.h
3.o:3.c symbol_table.h
