CC=gcc
DESTDIR=build/

all: power prime sumofvectors sumofmatrix clean grind

power: power.o
	mkdir -p build/; $(CC) $? --output build/$@

prime: prime.o
	mkdir -p build/; $(CC) $? --output build/$@

sumofvectors: Vector_Int.o sumofvectors.o
	mkdir -p build/; $(CC) $? --output build/$@

sumofmatrix: Vector_Int.o Matrix_Int.o sumofmatrix.o
	mkdir -p build/; $(CC) $? --output build/$@

grind:
	./grind.sh

clean:
	rm -rf *.o

dist-clean:
	rm -rf build/
