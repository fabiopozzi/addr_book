#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<signal.h>

void draw_menu(void);
static void finish(int sig);

int main(int argc, char **argv)
{
	initscr();		// init the curses library
	raw();			// line buffering disabled
	keypad(stdscr, TRUE);	// enables function keys reading
	noecho();

	mvprintw(0, 10, "FP address manager");
    {
        int ch;

        ch = getch();

        if (ch == KEY_F(1)) {
            printw("You pressed the F1 key");
        }
        else {
            printw("You pressed ");
            attron(A_BOLD);
            printw("%c", ch);
            attroff(A_BOLD);
        }
    }

	refresh();
	getch();
	endwin();

	// do your ncurses wrapup here

	exit(0);
}


