CC = gcc


all: 2.1.1 2.1.2 2.2.1 2.2.2 2.3.1 2.3.2

2.1.1:2_1_1.c
	$(CC) -pthread -o 2.1.1 2_1_1.c 
 

2.1.2:2_1_2.c
	$(CC) -pthread -o 2.1.2 2_1_2.c 


2.2.1:2_2_1.c
	$(CC) -pthread -o 2.2.1 2_2_1.c 


2.2.2:2_2_2.c
	$(CC) -pthread -o 2.2.2 2_2_2.c 


2.3.1:2_3_1.c
	$(CC) -pthread -o 2.3.1 2_3_1.c 


2.3.2:2_3_2.c
	$(CC) -pthread -o 2.3.2 2_3_2.c 



.PHONY: clean all

clean:
	rm -f *.o 2.1.1 2.1.2 2.2.1 2.2.2 2.3.1 2.3.2
