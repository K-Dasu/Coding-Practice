CC=g++
CFLAGS=-g -Wall


all: myprog

myprog: main.o Graph.o GraphNode.o TreeNode.o Node.o
	$(CC) $(CFLAGS) -o myprog main.o Graph.o GraphNode.o TreeNode.o Node.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.h
	$(CC) $(CFLAGS) -c Graph.cpp

GraphNode.o: GraphNode.cpp GraphNode.h
	$(CC) $(CFLAGS) -c GraphNode.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(CC) $(CFLAGS) -c TreeNode.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	rm myprog *.o *~
