CC=gcc
CFLAGS=-Wall
EXECUTABLE=linkedlist
list: linkedlist.o main.c
	$(CC) $(CFLAGS) linkedlist.o main.c -o $(EXECUTABLE)

linkedlist.o: linkedlist.h

clean:
	rm *o linkedlist 
