#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node {
    int id;
    char title[256];
    int wordCount;
    int charCount;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int id, char title[], int wordCount, int charCount);
void printTree(Node* root);

int idExists(Node* root, int id);


#endif