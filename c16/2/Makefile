CC=gcc
CFLAGS=-Wall -pedantic -ggdb

OBJS=linked_list.o 2.o

2: $(OBJS)
	$(CC) $(CFLAGS) -o 2 $(OBJS)

linked_list.o:linked_list.c linked_list.h
2.o:2.c linked_list.h
