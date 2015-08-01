CFLAGS=-c -Wall -Werror -pedantic -std=gnu99

all: addr_book

addr_book: main.o ab_curses.o
	gcc -lform -lncurses main.o ab_curses.o -o addr_book

main.o: main.c
	gcc $(CFLAGS) main.c

ab_curses.o: ab_curses.c
	gcc $(CFLAGS) ab_curses.c

clean:
	rm -r *.o addr_book
