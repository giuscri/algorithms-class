CC=cc
DESTDIR=build/
CFLAGS=-Wall -ansi
LDFLAGS=-lm

square: libpsgraph.o square.o
	mkdir -p build; $(CC) $(CFLAGS) $(LDFLAGS) $? --output build/$@

square.o: square.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

hanoiplayground: hanoiplayground.o Hanoi.o Stack_Int.o
	mkdir -p build; $(CC) $(CFLAGS) $(LDFLAGS) $? --output build/$@

hanoiplayground.o: hanoiplayground.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

Hanoi.o: Hanoi.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

stackintplayground: stackintplayground.o Stack_Int.o
	mkdir -p build; $(CC) $(CFLAGS) $(LDFLAGS) $? --output build/$@

stackintplayground.o: stackintplayground.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

Stack_Int.o: Stack_Int.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

koch: Koch.o libpsgraph.o koch.o
	mkdir -p build; $(CC) $(CFLAGS) $(LDFLAGS) $? --output build/$@

koch.o: koch.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

Koch.o: Koch.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

libpsgraph.o: libpsgraph.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $?

collatz: Vector_Int.o Vector_Collatz.o collatz.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

fibonacci: Vector_Int.o Vector_Fibonacci.o fibonacci.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

vectorsplayground: Vector_Int.o vectorsplayground.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

power: power.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

prime: prime.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

sumofvectors: Vector_Int.o sumofvectors.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

sumofmatrix: Vector_Int.o Matrix_Int.o sumofmatrix.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

garibald: garibald.o
	mkdir -p build/; $(CC) $(CFLAGS) $? --output build/$@

grind:
	bash grind.sh

clean:
	rm -rf *.o

distclean:
	rm -rf build/
