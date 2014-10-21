CC=gcc
DESTDIR=build/

all: power prime sumofarray sumofmatrix

power: power.o
	mkdir -p build/; $(CC) $? --output build/$@

prime: prime.o
	mkdir -p build/; $(CC) $? --output build/$@

sumofarray: sumofarray.o
	mkdir -p build/; $(CC) $? --output build/$@

sumofmatrix: sumofmatrix.o
	mkdir -p build/; $(CC) $? --output build/$@

clean:
	rm -rf *.o

dist-clean:
	rm -rf build/
