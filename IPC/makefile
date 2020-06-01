CC = gcc
FLAGS = -Wall -g

all: ping_pong

ping_pong:ping_pong.o
	$(CC) $(FLAGS) -o ping_pong ping_pong.o

ping_pong.o: ping_pong.c ping_pong.h
	$(CC) $(FLAGS) -c ping_pong.c 

.PHONY: clean all

clean:
	rm -f *.o ping_pong
