CC=gcc
CFLAGS=-Wall -ansi -pedantic -ggdb

OBJS=double_linked_list.o tests.o

tests: $(OBJS)
	$(CC) $(CFLAGS) -o tests $(OBJS)

double_linked_list.o:double_linked_list.c double_linked_list.h
tests.o:tests.c double_linked_list.h
