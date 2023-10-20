// bst.c
#include "bst.h"
#include <stdlib.h>
#include <string.h>

BST *createBST() {
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

Node *createNode(char *key, void *value) {
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void *searchBST(BST *tree, char *key) {
    Node *current = tree->root;
    while (current != NULL) {
        int cmp = strcmp(key, current->key);
        if (cmp == 0) {
            return current->value;
        } else if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

void insertBST(BST *tree, char *key, void *value) {
    Node *node = createNode(key, value);
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;
    while (current != NULL) {
        int cmp = strcmp(key, current->key);
        parent = current;
        if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (strcmp(key, parent->key) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

// ... (implementaciones de deleteBST y freeBST)