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

/*
 * ------------------------------------------------------------
 * | New Tree (Constructor)
 * ------------------------------------------------------------
 * This method should be called to initialize a tree before any
 * operations on the tree are performed.
 * */
Tree* Tree_New() {
    Tree* t = malloc(sizeof(Tree));
    //t->word[0] = '\0';
    t->word = NULL;
    t->count = 0;
    t->left = NULL;
    t->right = NULL;
    return t;
}

/*
 * ------------------------------------------------------------
 * | Destroy (Destructor)
 * ------------------------------------------------------------
 * This method destroys the entire binary tree by recursively
 * traversing to the bottom of the tree and then deallocating
 * memory for nodes as it traverses back to the root. Once there
 * are no more non NULL nodes, the tree is completely destroyed.
 * The function takes one argument - a pointer to a Tree.
 * ------------------------------------------------------------
 */
void destroy(Node* node) {
    if (node != NULL) {
        destroy(node->left);
        node->left = NULL;
        destroy(node->right);
        node->right = NULL;
        free(node->word);
        node->word = NULL;
        free(node); /* deallocate the memory for the node */
    }
}

/*
 * --------------------------------------------------------------------
 * | Insert
 * --------------------------------- -----------------------------------
 * This method inserts a word into the tree. If the word already exists,
 * the count of its node increases. Otherwise, a new node is created.
 *
 * Precondition: The tree passed to this method should be initialized
 * with Tree_New()
 * --------------------------------------------------------------------
 */
void insert(Node* node, char* word) {
    
    /* root case */
    if (node->word == NULL) {
        
        /* deep copy that dynamically allocates node->word */
        dynamicStrCpy(&node->word, word);
        
        node->count = 1;
        return;
    }
    
    /*
     * case 1: word < node->word      the key belongs to the left of the current node
     * case 2: word > node->word      the key belongs to the right of the current node
     * case 3: word == node-> word    the key is equal to the key of the current node
     * */
    if (strcmp(word, node->word) < 0) {
        /*
         * If there is immediate room on the left, place a node.
         * Otherwise, traverse left.
         * */
        if (node->left == NULL) {
            Node* tmp = malloc(sizeof(Node));
            tmp->left = NULL;
            tmp->right = NULL;
            
            /* deep copy that dynamically allocates tmp->word */
            dynamicStrCpy(&tmp->word, word);
            
            tmp->count = 1;
            node->left = tmp;
            
        } else {
            insert(node->left, word);
        }
    } else if (strcmp(word, node->word) > 0) {
        /*
         * If there is immediate room on the right, place a node.
         * Otherwise, traverse right.
         * */
        if (node->right == NULL) {
            Node *tmp = malloc(sizeof(Node));
            tmp->left = NULL;
            tmp->right = NULL;
            
            /* deep copy that dynamically allocates tmp->word */
            dynamicStrCpy(&tmp->word, word);
            
            tmp->count = 1;
            node->right = tmp;
        } else {
            insert(node->right, word);
        }
    } else { /* found the same word */
        ++node->count;
    }
}

/*
 * ----------------------------------------------------
 * | Write Inorder
 * ----------------------------------------------------
 * This is a simple recursive method that writes the
 * contents of the tree to a file.
 * ----------------------------------------------------
 * */
void writeInorder(Node *node, FILE *out) {
    if (node == NULL) return;
    writeInorder(node->left, out);
    fprintf(out, "%s: %d\n", node->word, node->count);
    writeInorder(node->right, out);
}
