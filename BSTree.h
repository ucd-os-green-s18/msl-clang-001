#ifndef BSTree
#define BSTree

#include <stdio.h>
#include <stdlib.h>

/*
 * Tree Specification:
 * The tree has to be a self referential C struct, containing a
 * dynamically allocated word, its integer count, and pointers to
 * the left and right subtrees.
 * */

/*
 * How to dynamically allocate a string:
 * word = (char*) malloc(sizeof(char) * (length + 1));
 * */
struct Tree {
    char word[255];
    int count;
    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree Tree; /* simplifies type declaration */
typedef struct Tree Node; /* a tree is a node */

/* FUNCTION PROTOTYPES */
Tree* Tree_New();          /* constructor */
void destroy(Tree*);       /* to free memory */
void insert(Tree*, char*);
void writeInorder(Tree*, FILE*);

/*
 * Prototypes for string manipulation functions undeserving
 * of their own header and c files.  These are very basic and only
 * used to avoid using the string library.
 */
void copyStrings(char* destination, char* source);
int compareStrings(char* leftString, char* rightString);
#endif