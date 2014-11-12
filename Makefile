CC=gcc
CFLAGS=-Wall -ansi -g -DDEBUG

playground: playground.o Graph.o Node_Int.o Linkedlist.o Queue.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

playground.o: playground.c
	$(CC) $(CFLAGS) -c $?

Graph.o: Graph.c
	$(CC) $(CFLAGS) -c $?

Node_Int.o: Node_Int.c
	$(CC) $(CFLAGS) -c $?

Linkedlist.o: Linkedlist.c
	$(CC) $(CFLAGS) -c $?

Queue.o: Queue.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f *.o

distclean:
	rm -rf builds
