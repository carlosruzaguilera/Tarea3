#include <stdio.h>
#include "bst.h"
#include "document.h"  // Para acceder a la estructura Document
#include <stdlib.h>

TreeNode* insert(TreeNode *root, Document doc) {
    // Código de la función
    return root;  // Asegúrate de retornar el nodo raíz actualizado
}

BST* createBST() {
    BST *bst = (BST *)malloc(sizeof(BST));
    if (bst == NULL) {
        perror("Error al crear BST");
        exit(EXIT_FAILURE);
    }
    bst->root = NULL;
    return bst;
}

void cleanupBST(BST *bst) {
    freeBSTNodes(bst->root);  // Función auxiliar para liberar memoria recursivamente
    free(bst);
}

// Función auxiliar para liberar memoria recursivamente
void freeBSTNodes(TreeNode *node) {
    if (node != NULL) {
        freeBSTNodes(node->left);
        freeBSTNodes(node->right);
        free(node->doc.title);  // Asegurando que el título es una cadena dinámica
        free(node);
    }
}