CC=gcc
CFLAGS=-Wall -ansi -pedantic -ggdb

OBJS=double_linked_list.o 3.o

2: $(OBJS)
	$(CC) $(CFLAGS) -o 3 $(OBJS)

double_linked_list.o:double_linked_list.c double_linked_list.h
3.o:3.c double_linked_list.h
