#include<stdio.h>
#include<stdlib.h>

struct list_t
{
    int idx;
    char *nome;
    char *cognome;
    struct list_t *next;
};

struct list_t *b1 = NULL;
int i=0;

int add_to_book(struct list_t **book)
{
    struct list_t *tmp;

    tmp = (struct list_t *)malloc(sizeof(struct list_t));
    if (tmp == NULL) {
        printf("[error] Malloc failed\n"); // TODO: rimpiazzare con fprintf(stderr) ?
        return -1;                         // TODO: usare valori di ritorno codificati ?
    }

    // inserimento in testa
    tmp->next = *book;
    tmp->idx = i;
    *book = tmp;
    printf("aggiunto elemento %d\n",i);
    i++;

    return 0;
}

int print_book(struct list_t *book)
{
    struct list_t *tmp = book;
    struct list_t *el;

    while (tmp != NULL)
    {
        printf("elemento lista numero %d\n", tmp->idx);
        el = tmp;
        tmp = tmp->next;
        free(el);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char c,foo;
    int go = 1;
    // TODO: usare getopt?
    printf("cosa fare?\n");
    printf("a per aggiungere un record\n");
    printf("e per uscire\n");
    while (go) {
        printf("> ");
        scanf("%c%c", &c, &foo);
        switch (c)
        {
            case 'a':
                add_to_book(&b1);
                printf("ora b1 vale %p\n", b1);
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




