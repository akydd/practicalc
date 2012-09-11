CC=gcc
CFLAGS=-Wall -ansi -pedantic

OBJS=search_open.o 2.o

2: $(OBJS)
	$(CC) $(CFLAGS) -o 2 $(OBJS)

search_open.o:search_open.c search_open.h
2.o:2.c search_open.h
