#ifndef BST_H
#define BST_H

#include "document.h"  // Incluye la definición de Document

typedef struct TreeNode {
    Document doc;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct BST {
    TreeNode *root;
} BST;

// Función para insertar un nuevo nodo en el BST
TreeNode* insert(TreeNode *root, Document doc);

// Función para crear un nuevo BST
BST* createBST();

// Función para liberar la memoria utilizada por el BST
void cleanupBST(BST *bst);

// Función para buscar un documento por título en el BST
TreeNode* searchBST(TreeNode* root, const char* title);

// Función para realizar un recorrido en orden del BST
void inorderTraversal(BST* tree, void (*func)(TreeNode*));

// Función auxiliar para inorderTraversal
static void inorderTraversalHelper(TreeNode* node, void (*func)(TreeNode*));

// Función para imprimir la información de un documento
void print_document_info(TreeNode* node);

// Función para liberar la memoria utilizada por los nodos del BST
void freeBSTNodes(TreeNode* node);

#endif  // BST_H