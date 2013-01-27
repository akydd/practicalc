CC=gcc
CFLAGS=-Wall -ansi -pedantic -ggdb
OBJS=cross_ref.o scan.o
TEST_OBJS=cross_ref.o tests.o

scan: $(OBJS)
	$(CC) $(CFLAGS) -o scan $(OBJS)

tests: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o tests $(TEST_OBJS)

cross_ref.o:cross_ref.h cross_ref.c
scan.o:cross_ref.h scan.c
tests.o:cross_ref.h tests.c

clean:
	rm *.o
