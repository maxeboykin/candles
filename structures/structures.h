#define HASH_SIZE 101
#include <stdlib.h>
#include <string.h>
char *str_dup(char *s);
static struct nlist *hashtable[HASH_SIZE];
struct nlist {
    int key;
    struct nlist *next;
    char *first;
    char *last;
    int *month;
    int *day;
    int *year;
};

typedef struct {
    char *first;
    char *last;
    int *month;
    int *day;
    int *year;
} friend;


void print_hashtable(){
    for(unsigned i = 0; i < HASH_SIZE - 1; i++){
        struct nlist *p = hashtable[i];
        if(p != NULL) printf("%s %s\n", p->first, p->last);
        while(p != NULL && p->next != NULL){
            p = p->next;
            printf("%s %s\n", p->first, p->last);
        }
    }
}

struct nlist *lookup(char *s){
    struct nlist *np;
    for(np = hashtable[hash(s)]; np != NULL; np = np->next){

    }
}

struct nlist *install(friend friend){
    struct nlist *np;
    unsigned hashval;
    if((np = lookup(first)) == NULL) /* not found */ {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = str_dup(name)) == NULL){
            return NULL;
        }
    }
}

char *str_dup(char *s){
    char *p;
    p = (char *) malloc(strlen(s)+1); // +1 for '\0'
    if(p != NULL){
        strcpy(p, s);
    }
    return p;
}


void getUserInput(){

}