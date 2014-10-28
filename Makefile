CC=cc
CFLAGS=-Wall -ansi
LDFLAGS=-lm

all: splittime swap reverse upper rectangleplayground

smallest: smallest.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

smallest.o: smallest.c
	$(CC) $(CFLAGS) -c $?

max_secondmax: max_secondmax.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

max_secondmax.o: max_secondmax.c
	$(CC) $(CFLAGS) -c $?

rectangleplayground: rectangleplayground.o Point_Int.o Rectangle_Int.o
	mkdir -p builds; $(CC) $(CFLAGS) $(LDFLAGS) $? --output builds/$@

rectangleplayground.o: rectangleplayground.c
	$(CC) $(CFLAGS) -c $?

Rectangle_Int.o: Rectangle_Int.c
	$(CC) $(CFLAGS) -c $?

Point_Int.o: Point_Int.c
	$(CC) $(CFLAGS) -c $?

upper: upper.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

upper.o: upper.c
	$(CC) $(CFLAGS) -c $?

reverse: reverse.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

reverse.o: reverse.c
	$(CC) $(CFLAGS) -c $?

swap: swap.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

swap.o: swap.c
	$(CC) $(CFLAGS) -c $?

splittime: splittime.o
	mkdir -p builds; $(CC) $(CFLAGS) $? --output builds/$@

splittime.o: splittime.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f *.o

distclean:
	rm -rf builds
