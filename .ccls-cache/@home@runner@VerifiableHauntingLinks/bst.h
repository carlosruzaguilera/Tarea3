#ifndef BST_H
#define BST_H

#include "document.h"  // Incluye la definición de Document

// Nodo de árbol binario para almacenar documentos
typedef struct TreeNode {
    Document doc;
    struct TreeNode *left, *right;
} TreeNode;

// Definición de la estructura BST (Árbol Binario de Búsqueda)
typedef struct BST {
    TreeNode *root;
} BST;

TreeNode* insert(TreeNode *root, Document doc);

BST* createBST();
void insert(BST* tree, Document doc);
void inorderTraversal(TreeNode* node);  // Función para recorrer y mostrar el árbol en orden
void freeBSTNodes(TreeNode* node);  // Función para liberar la memoria utilizada por los nodos del árbol
void cleanupBST(BST* tree);  // Función para liberar la memoria utilizada por el árbol

#endif // BST_H