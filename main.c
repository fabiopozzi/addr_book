#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>

//void draw_menu(void);
//static void finish(int sig);

int main(int argc, char **argv)
{
    int rows,cols;      // number of rows and columns of the current window
    char msg[] = "FP address manager";

	initscr();		// init the curses library
	raw();			// line buffering disabled
	keypad(stdscr, TRUE);	// enables function keys reading
	noecho();
    getmaxyx(stdscr, rows, cols);

	mvprintw(0, (cols-strlen(msg))/2 , msg);
    {
        int ch;

        ch = getch();

        if (ch == KEY_F(1)) {
            mvprintw(2, (cols-strlen(msg))/2, "You pressed the F1 key");
        }
        else {
            mvprintw(2, (cols-strlen(msg))/2, "You pressed ");
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


