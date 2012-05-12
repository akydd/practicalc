CFLAGS=-Wall -Wextra

OBJ1=profile.o 1.o
OBJ2=datetime.o 2.o
OBJ4=datetime.o flight_info.o 4.o

all: 1 2 4

1: $(OBJ1)
	$(CC) $(CFLAGS) -o 1 $(OBJ1)

2: $(OBJ2)
	$(CC) $(CFLAGS) -o 2 $(OBJ2)

4: $(OBJ4)
	$(CC) $(CFLAGS) -o 4 $(OBJ4)

1.o:profile.h 1.c
profile.o:profile.h profile.c

2.o:datetime.h 2.c
datetime.o:datetime.h datetime.c

4.o:flight_info.h 4.c
flight_info.o:flight_info.h flight_info.c

clean:
	rm *.o
