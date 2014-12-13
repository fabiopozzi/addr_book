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

	initscr();		// init the curses library
    clear();
    cbreak();
	noecho();
    keypad(stdscr, TRUE);

    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

    for (i=0; i< n_choices; i++)
        my_items[i] = new_item(choices[i], ch_description[i]);
    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);
    mvprintw(LINES -2, 0, "F1 to exit");
    post_menu(my_menu);
    refresh();

    while ((c = getch()) != KEY_F(1))
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
    }
    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();
    return 0;
}
