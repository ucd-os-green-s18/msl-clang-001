/*
 * Created by:
 * Matthew Moltzau and Michael Hedrick
 * Spring 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"
#include "HelperFunctions.h"

#define MAX_WORD 255 /* arbitrary value */

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
    
    Tree *tree = Tree_New();
    while (fscanf(in, "%s", buff) != EOF) {
        insert(tree, buff); /* buff is a c string, we will pass a pointer */
    }
    
    /* Inserting into a tree automatically sorts, so now we can print. */
    FILE *out = fopen("./program_output.txt", "w");
    writeInorder(tree, out);
    
    /* Cleanup */
    fclose(in);
    fclose(out);
    destroy(tree);
    puts("The program has finished executing.");
    exit(0);
}

/*
 * -----------------------------------------------
 * Dynamic String Copy
 * -----------------------------------------------
 * This method will dynamically allocate a new
 * c string using the length of another one, then
 * copy that string over.
 *
 * This method accepts a pointer to a pointer so that
 * the memory allocation performed does not disappear
 * after the method returns.
 */
void dynamicStrCpy(char** newStr, char* oldStr) {
    *newStr = (char*) malloc(sizeof(char) * (strlen(oldStr) + 1));
    if(*newStr == NULL) {
        puts("Error. Memory allocation not successful.");
        exit(2);
    }
    strcpy(*newStr, oldStr);
}