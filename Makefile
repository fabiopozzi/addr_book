CFLAGS=-c -Wall -Werror -pedantic -std=c99

all: addr_book

addr_book: main.o
	gcc main.o -o addr_book

main.o: main.c
	gcc $(CFLAGS) main.c

clean:
	rm -r *.o addr_book
