/*
 * Created by:
 * Matthew Moltzau and Michael Hedrick
 * Spring 2018
 */

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
struct Tree {
    char *word;
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

#endif