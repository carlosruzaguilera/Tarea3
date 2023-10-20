// bst.h
#ifndef BST_H
#define BST_H

typedef struct Node {
    char *key;
    void *value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BST {
    Node *root;
} BST;

BST *createBST();
void *searchBST(BST *tree, char *key);
void insertBST(BST *tree, char *key, void *value);
void deleteBST(BST *tree, char *key);
void freeBST(BST *tree);

#endif // BST_H
