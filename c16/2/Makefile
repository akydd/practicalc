CC=gcc
CFLAGS=-Wall -pedantic -ggdb

OBJS=linked_list.o tests.o

tests: $(OBJS)
	$(CC) $(CFLAGS) -o tests $(OBJS)

linked_list.o:linked_list.c linked_list.h
tests.o:tests.c linked_list.h
