#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 20

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
    char line[30];

    tmp = (struct list_t *)malloc(sizeof(struct list_t));
    if (tmp == NULL) {
        printf("[error] Malloc failed\n"); // TODO: rimpiazzare con fprintf(stderr) ?
        return -1;                         // TODO: usare valori di ritorno codificati ?
    }

    // inserimento in testa
    tmp->next = *book;
    tmp->idx = i;
    tmp->nome = (char *)malloc(STR_MAX_LEN * sizeof(char));
    if(tmp->nome == NULL)
        return -1;
    printf("Inserisci nome, (max 20 caratteri)\n");
    if (fgets(line, sizeof(line), stdin) != NULL) {
        sscanf(line,"%[^\n]", tmp->nome);
    }
    else {
        return -1;
    }
    *book = tmp;
    printf("aggiunto elemento %d\n",i);
    i++;

    return 0;
}

int print_book(struct list_t *book)
{
    struct list_t *lp, *oldlp;

    for(lp = book; lp != NULL; oldlp = lp, lp = lp->next, free(oldlp))
    {
        printf("elemento lista numero %d\n", lp->idx);
        if (lp->nome != NULL) {
            printf("Nome: %s\n",lp->nome);
            free(lp->nome);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char c,foo;
    int go = 1;
    int ret;
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
                ret = add_to_book(&b1);
                if(ret < 0)
                    return -1;
                printf("ora b1 vale %p\n", b1);
                break;
            case 'e':
                go = 0;
                break;
            default:
                printf("opzione %c non riconosciuta\n", c);
                break;
        }
    }
    printf("hai deciso di uscire, stampo il libro attuale\n");
    print_book(b1);
    
    return 0;
}




