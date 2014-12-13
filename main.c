#include<stdio.h>
#include<stdlib.h>

struct list_t
{
    lista *next;
    int idx;
    char *nome;
    char *cognome;
} lista;

lista *b1 = NULL;
int i=0;

int add_to_book(lista *book)
{
    lista *tmp;
    if (book == NULL) {
        tmp = (lista *)malloc(sizeof(lista));
        if (tmp == NULL) {
            printf("[error] Malloc failed\n"); // TODO: rimpiazzare con fprintf(stderr) ?
            return -1;                         // TODO: usare valori di ritorno codificati ?
        }
        book = tmp;
    }
    else {
        // inserimento in testa
        tmp->next = book;
        tmp->idx = i;
        book = tmp;
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char c;
    int go = 1;
    // TODO: usare getopt?
    printf("cosa fare?\n");
    printf("a per aggiungere un record\n");
    printf("e per uscire\n");
    while (go) {
        printf("> ");
        c = getch();
        switch (c)
        {
            case 'a':
                add_to_book(b1);
                break;
            case 'e':
                go = 0;
                break;
            default:
                printf("opzione non riconosciuta\n");
                break;
        }
    }
    printf("hai deciso di uscire, stampo il libro attuale\n");
    print_book(b1);
    
    return 0;
}




