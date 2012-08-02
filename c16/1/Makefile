CC=gcc
CFLAGS=-Wall -pedantic -ggdb
OBJS=cross_ref.o scan.o

scan: $(OBJS)
	$(CC) $(CFLAGS) -o scan $(OBJS)

cross_ref.o:cross_ref.h cross_ref.c
scan.o:cross_ref.h scan.c

clean:
	rm *.o
