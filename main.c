#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<signal.h>

void draw_menu(void);
static void finish(int sig);

int main(int argc, char **argv)
{
	initscr();		// init the curses library

	printw("FP address manager");
	refresh();
	getch();
	endwin();

	// do your ncurses wrapup here

	exit(0);
}


