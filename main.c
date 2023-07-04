#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "structures/structures.h"
#include <string.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("this should provide birthdays in next five weeks");
    } else if (argc == 2) { // first name or last name only
        char *entry = *++argv;
        if(strcmp(entry, "all") == 0){
            print_hashtable();
        }
        printf("look up the people with first names or last names matching");
    } else if (argc == 3) { // first and last name
        printf("look up exact person mentioned");
    }

}