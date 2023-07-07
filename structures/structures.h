#define HASH_SIZE 101
#include <stdlib.h>
#include <string.h>
char *str_dup(char *s);
static struct friend *hashtable[HASH_SIZE];
//struct nlist {
//    int key;
//    struct nlist *next;
//    char *first;
//    char *last;
//    int *month;
//    int *day;
//    int *year;
//};

struct friend {
    int key;
    struct friend *next;
    char *first;
    char *last;
    int month;
    int day;
    int year;
};


void print_hashtable(){
    for(unsigned i = 0; i < HASH_SIZE - 1; i++){
        struct friend *f = hashtable[i];
        // calculate age of friend here and place in print below
        if(f != NULL) printf("%s %s %d %d %d\n", f->first, f->last, f->month, f->day, f->year);
        while(f != NULL && f->next != NULL){
            f = f->next;
            printf("%s %s %d %d %d\n", f->first, f->last, f->month, f->day, f->year);
        }
    }
}

/*hash: form hash value for string s */
unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASH_SIZE;
}

struct friend *lookup(char *first){
    struct friend *np;
    for(np = hashtable[hash(first)]; np != NULL; np = np->next){
        // there can be collisions for different names
        // this is why you need to look through
        if (strcmp(first, np->first) == 0){
            return np; /* found */
        }
    }
    return NULL;
}

struct friend *install(char *first, char *last, int month, int day, int year){
    struct friend *np;
    unsigned hashval;
    if((np = lookup(first)) == NULL) /* not found */ {
        np = (struct friend *) malloc(sizeof(*np));
        if(np == NULL || (np->first = str_dup(first)) == NULL){
            return NULL;
        }
        hashval = hash(first);
        np->next = hashtable[hashval]; // old head
        hashtable[hashval] = np;
    } else {
        free((int *) np->month);
        free((int *) np->year);
        free((int *) np->day);
    }
    if((np->))
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