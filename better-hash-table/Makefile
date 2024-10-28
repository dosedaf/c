CC=gcc
CFLAGS=-I.
DEPS = hashtable.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: main.o
	$(CC) -o main main.o
