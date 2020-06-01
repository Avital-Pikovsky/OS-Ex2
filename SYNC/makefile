CC = gcc
FLAGS = -Wall -g

all: 2.1.1 2.1.2 2.2.1 2.2.2 2.3.1 2.3.2

2.1.1:2.1.1.o
	$(CC) $(FLAGS) -o ping_pong ping_pong.o

2.1.1.o: 2.1.1.c 2.1.1.h
	$(CC) $(FLAGS) -c 2.1.1.c 

2.1.2:2.1.2.o
	$(CC) $(FLAGS) -o 2.1.2 2.1.2.o

2.1.2.o: 2.1.2.c 2.1.2.h
	$(CC) $(FLAGS) -c 2.1.2.c 

2.2.1:2.2.1.o
	$(CC) $(FLAGS) -o 2.2.1 2.2.1.o

2.2.1.o: 2.2.1.c 2.2.1.h
	$(CC) $(FLAGS) -c 2.2.1.c 

2.2.2:2.2.2.o
	$(CC) $(FLAGS) -o 2.2.2 2.2.2.o

2.2.2.o: 2.2.2.c 2.2.2.h
	$(CC) $(FLAGS) -c 2.2.2.c 

2.3.1:2.3.1.o
	$(CC) $(FLAGS) -o 2.3.1 2.3.1.o

2.3.1.o: 2.3.1.c 2.3.1.h
	$(CC) $(FLAGS) -c 2.3.1.c 

2.3.2:2.3.2.o
	$(CC) $(FLAGS) -o 2.3.2 2.3.2.o

2.3.2.o: 2.3.2.c 2.3.2.h
	$(CC) $(FLAGS) -c 2.3.2.c 



.PHONY: clean all

clean:
	rm -f *.o 2.1.1 2.1.2 2.2.1 2.2.2 2.3.1 2.3.2
