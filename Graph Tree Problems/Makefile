CC=g++
CFLAGS=-g -Wall


all: myprog

myprog: main.o GraphNode.o TreeNode.o Node.o
	$(CC) $(CFLAGS) -o myprog main.o GraphNode.o TreeNode.o Node.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

GraphNode.o: GraphNode.cpp GraphNode.h
	$(CC) $(CFLAGS) -c GraphNode.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(CC) $(CFLAGS) -c TreeNode.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	rm myprog *.o *~
