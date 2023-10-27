#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

// Función para insertar un nuevo nodo en el árbol binario
Node* insert(Node* root, int id, char title[], int wordCount, int charCount) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->id = id;
        strcpy(root->title, title);
        root->wordCount = wordCount;
        root->charCount = charCount;
        root->left = root->right = NULL;
    } else if (id < root->id) {
        root->left = insert(root->left, id, title, wordCount, charCount);
    } else if (id > root->id) {
        root->right = insert(root->right, id, title, wordCount, charCount);
    }
    return root;
}

// Función para imprimir los títulos de los libros en el árbol
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("ID: %d, Title: %s, Words: %d, Characters: %d\n", root->id, root->title, root->wordCount, root->charCount);
        printTree(root->right);
    }
}

int idExists(Node* root, int id) {
    if (root == NULL) {
        return 0;
    }
    if (root->id == id) {
        return 1;
    } else if (id < root->id) {
        return idExists(root->left, id);
    } else {
        return idExists(root->right, id);
    }
}