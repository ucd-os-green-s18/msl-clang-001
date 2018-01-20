#include <stdlib.h>
#include <printf.h>

/*****************************************************************/
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
    char *word;
    int count;
    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree Tree; /* simplifies type declaration */
typedef struct Tree Node; /* a tree is a node */

/* TREE FUNCTION PROTOTYPES */
/* TODO lookup "extern" */
Tree* Tree_New();          /* constructor */
void destroy(Tree*);       /* to free memory */
void insert(Tree*, char*);
/* void removeKey(Tree*, char*); unused */
void writeInorder(Tree*, FILE*);
/*****************************************************************/

/* arbitrarily large value */
#define MAX_WORD 255

int main(int argc, char **argv) {
    
    if (argc != 2) {
        /* TODO how to run args from CLion, then change this */
        puts("usage: hwk1 input_file");
    }
    
    /* OPENING FILE */
    char buff[MAX_WORD]; /* buff is simply a word */
    FILE *in = fopen("../input02.txt", "r");
    if (in == NULL) {
        puts("There was an error opening the file. Exiting now.");
        exit(1);
    }
    
    Tree *tree = Tree_New();
    while (fscanf(in, "%s", buff) != EOF) {
        insert(tree, buff);
        /* puts(buff); debug print */
    }
    
    /* Inserting into a tree automatically sorts, so now we can print. */
    FILE *out = fopen("../myOutput02.txt", "w");
    writeInorder(tree, out);
    
    /* Cleanup */
    fclose(in);
    fclose(out);
    destroy(tree);
    exit(0);
}

/* TREE IMPLEMENTATION */
Tree* Tree_New() {
    Tree* t = malloc(sizeof(Tree));
    t->word = NULL;
    t->count = NULL;
    t->left = NULL;
    t->right = NULL;
    return t;
}

/*
 * Note:
 * Initial calls are the tree, or head pointer, but
 * the recursion will have us traversing nodes. Not
 * that there is a meaningful difference between these
 * in the implementation.
 * */

void destroy(Node* node) {
    /* TODO */
}

void insert(Node* node, char* word) {
    /* TODO */
}


/* void removeKey(Node* node, char* word) {} */

void writeInorder(Node *node, FILE *out) {
    if (node == NULL) return;
    writeInorder(node->left, out);
    fprintf(out, "%s: %d\n", node->word, node->count);
    writeInorder(node->right, out);
}