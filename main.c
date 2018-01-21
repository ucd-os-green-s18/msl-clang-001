#include <stdio.h>
#include <stdlib.h>
#include <printf.h>
#include <string.h>
#include "BSTree.h"

/* arbitrarily large value */
#define MAX_WORD 255

int main(int argc, char **argv) {
    
    if (argc != 2) {
        puts("usage: hwk1 input_file");
        exit(1);
    }
    
    char filename[80];
    strcpy(filename, "./");
    strcat(filename, argv[1]);
    
    /* OPENING FILE */
    char buff[MAX_WORD];
    FILE *in = fopen(filename, "r");
    if (in == NULL) {
        puts("There was an error opening the file. Exiting now.");
        exit(1);
    }
    
    puts("opened the file");
    
    Tree *tree = Tree_New();
    while (fscanf(in, "%s", buff) != EOF) {
        
        puts("before insert");
        insert(tree, buff); /* buff is a c string, we will pass a pointer */
        puts("after insert");
        /* puts(buff); debug print */
    }
    
    puts("finished inserting");
    
    /* Inserting into a tree automatically sorts, so now we can print. */
    FILE *out = fopen("./program_output.txt", "w");
    writeInorder(tree, out);
    
    puts("done writing");
    
    /* Cleanup */
    fclose(in);
    fclose(out);
    destroy(tree);
    exit(0);
}