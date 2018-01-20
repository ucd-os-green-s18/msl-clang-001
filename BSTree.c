#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

Tree* Tree_New() {
    Tree* t = malloc(sizeof(Tree));
    t->word = NULL;
    t->count = 0;
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