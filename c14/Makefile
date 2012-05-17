CFLAGS=-Wall -Wextra -pedantic -DMAX=200 $(OPTFLAGS)
OBJS=mmult.o 2.o

2: $(OBJS)
	# Needed '-lm' to pick up math libs.
	# '-lm' must appear AFTER all libs that need it.
	$(CC) $(CFLAGS)  -o 2 $(OBJS) -lm

mmult.o:mmult.h mmult.c
2.o:mmult.h 2.c

clean:
	rm *.o
