CC=gcc
CFLAGS=-I.

sc20d: sc20d.o
	$(CC) -o sc20d sc20d.c -I.

clean:
	rm *.o
