#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<menu.h>

#define WIDTH 30
#define HEIGHT 10

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD   4

char *choices[] = {
                "Choice 1",
                "Choice 2",
                "Scelta 3",
                "Scelta 4",
                "EXIT",
};
char *ch_description[] = {
                "BLABLA 1",
                "BLABLA 2",
                "BLABLA 3",
                "BLABLA 4",
                "Esci dal programma",
};
void print_menu(WINDOW *menu_win, int highlight);
                        

int main(int argc, char **argv)
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;

	initscr();		// Init the curses library
    start_color();
    cbreak();
	noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);

    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i=0; i< n_choices; i++)
        my_items[i] = new_item(choices[i], ch_description[i]);
    
    /* Create menu */
    my_menu = new_menu((ITEM **)my_items);
    
    /* Create the window to be associated with the menu */
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 28, 3, 1));

    /* Set menu mark to the string " * " */
    set_menu_mark(my_menu, " * ");
    
    /* Print a border around the main window and print a little */
    box(my_menu_win, 0, 0);
    print_in_middle (my_menu_win, 1, 0, 40, "My menu", COLOR_PAIR(1));
    mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
    mvwhline(my_menu_win, 2, 0, ACS_HLINE, 38);
    mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
    mvprintw(LINES - 2, 0, "F1 to quit");

    refresh();

    post_menu(my_menu);
    wrefresh(my_menu_win);

    while ((c = wgetch(my_menu_win)) != KEY_F(1))
    {
        switch (c)
        {
            case KEY_DOWN:
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
        }
        wrefresh(my_menu_win);
    }
    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();
    return 0;
}
