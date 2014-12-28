#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include <form.h>

void curs_main(void)
{
    /* Init curses */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void print_choice(void)
{
    int ch;

    mvprintw(4, 10, "Welcome to the Address Book");
    mvprintw(6, 10, "Press 'a' if you want to add a record");
    mvprintw(8, 10, "Press 'p' to print the current address book");
    mvprintw(10, 10, "Press F1 to exit");
    /* Loop through to get user requests */
    /* F1 to exit */
    while((ch = getch()) != KEY_F(1))
    {
        switch(ch)
        {
        case 'a':
            clear();
            refresh();
            mvprintw(4, 10, "Add a new record");
            break;
        case 'p':
            clear();
            refresh();
            mvprintw(4, 10, "Print all records");
            break;
        default:
            /* if it's a normal char, it gets printed */
            /*form_driver(my_form, ch);*/
            break;
        }
    }
}


int print_menu(void)
{
    FIELD *field[4];
    FORM    *my_form;
    int ch;
    /* Init fields */
    field[0] = new_field(1, 10, 4, 18, 0, 0);
    field[1] = new_field(1, 10, 6, 18, 0, 0);
    field[2] = new_field(1, 10, 8, 18, 0, 0);
    field[3] = NULL;

    set_field_back(field[0], A_UNDERLINE);
    field_opts_off(field[0], O_AUTOSKIP);

    set_field_back(field[1], A_UNDERLINE);
    field_opts_off(field[1], O_AUTOSKIP);

    set_field_back(field[2], A_UNDERLINE);
    field_opts_off(field[2], O_AUTOSKIP);

    /* Create the form and post it */
    my_form = new_form(field);
    post_form(my_form);
    refresh();

    mvprintw(4, 10, "Value1: ");
    mvprintw(6, 10, "Value2: ");
    mvprintw(8, 10, "Value3: ");
    refresh();

    /* Loop through to get user requests */
    /* F1 to exit */
    while((ch = getch()) != KEY_F(1))
    {
        switch(ch)
        {
        case KEY_DOWN:
            /* Go to next field */
            form_driver(my_form, REQ_NEXT_FIELD);
            /* Go to the end of the present buffer */
            /* Leaves nicely at the last character */
            form_driver(my_form, REQ_END_LINE);
            break;
        case KEY_UP:
            /* go to previous field */
            form_driver(my_form, REQ_PREV_FIELD);
            form_driver(my_form, REQ_END_LINE);
            break;
        default:
            /* if it's a normal char, it gets printed */
            form_driver(my_form, ch);
            break;
        }
    }

    /* Un-post form and free memory */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);

    endwin();
    return 0;
}

