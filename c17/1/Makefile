CC=gcc
CFLAGS=-Wall -ansi -pedantic -ggdb

OBJS=page_formatter.o 1.o

1: $(OBJS)
	$(CC) $(CFLAGS) -o 1 $(OBJS)

page_formatter.o:page_formatter.c page_formatter.h
1.o:1.c page_formatter.h
