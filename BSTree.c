#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*
 * Void destroy destroys the entire binary tree by
 * recursively traversing to the bottom of the tree and then
 * deallocating memory for nodes as it traverses back to the root.
 * Once there are no more non NULL nodes, the
 * tree is completely destroyed.
 * The function takes one argument - a pointer to a Tree.
 */
void destroy(Node* node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        free(node);           /* deallocate the memory for the node */
    }
}

/*
 * Void insert inserts a word into the tree.  First,
 * each node is checked for the word and if the word already exists,
 * that node's count is incremented.  Otherwise, a new node
 * is created at the appropriate position in the tree.
 */
void insert(Node* node, char* _word) {
    
    /* Return a negative number if _word < node->word */
    if (strcmp(_word, node->word) < 0) {
        if (node->left != NULL) {
            insert(node->left, _word);
        } else {
            /* Allocate a new node(Tree) and initialize its data */
            Node* n = malloc(sizeof(Node));
            n->word = _word;
            node->left = n; /* Put the new node in its place */
        }
    }
    /* Return a positive number if _word > node->word */
    else if (strcmp(_word, node->word) > 0) {
        if (node->right != NULL) {
            insert(node->right, _word);
        } else {
            /* Allocate a new node(Tree) and initialize its data */
            Node *n = malloc(sizeof(Node));
            n->word = _word;
            node->right = n; /* Put the new node in its place */
        }
    }
    /* Return 0 if _word == node->word */
    else {
        ++node->count;
    }

}


/* void removeKey(Node* node, char* word) {} */

void writeInorder(Node *node, FILE *out) {
    if (node == NULL) return;
    writeInorder(node->left, out);
    fprintf(out, "%s: %d\n", node->word, node->count);
    writeInorder(node->right, out);
}