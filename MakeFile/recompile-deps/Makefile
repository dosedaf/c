CC=gcc
CFLAGS=-I.
DEPS= heisenberg.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

saymake: main.o say.o
	$(CC) -o say main.o say.o
