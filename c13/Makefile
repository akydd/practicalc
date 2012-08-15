CFLAGS=-Wall -Wextra -pedantic -ggdb
OBJS=~/practicalc/c11/profile.o file_format.o 6.o

all: 1 2 3 4a 4b 5 6

6: $(OBJS)
	$(CC) $(CFLAGS) -o 6 $(OBJS)


6.o:file_format.h ~/practicalc/c11/profile.h 6.c
~/practicalc/c11/profile.o:~/practicalc/c11/profile.h ~/practicalc/c11/profile.c
file_format.o:file_format.h file_format.c

clean:
	rm *.o
