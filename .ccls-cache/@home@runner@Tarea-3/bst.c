#include "bst.h"
#include <stdlib.h>
#include <string.h>

TreeNode* insert(TreeNode *root, Document doc) {
    if (root == NULL) {
        TreeNode* new_node = (TreeNode *)malloc(sizeof(TreeNode));
        if (new_node == NULL) {
            perror("Error al crear nuevo nodo");
            exit(EXIT_FAILURE);
        }
        new_node->doc = doc;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    int comparison = strcmp(doc.title, root->doc.title);
    if (comparison < 0) {
        root->left = insert(root->left, doc);
    } else if (comparison > 0) {
        root->right = insert(root->right, doc);
    } // Si la comparación es 0, el título ya existe en el árbol, así que no hacemos nada.

    return root;  // Retorna la raíz del árbol, que podría ser un nuevo nodo si la raíz era NULL.
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

TreeNode* searchBST(TreeNode* root, const char* title) {
    if (root == NULL || strcmp(root->doc.title, title) == 0) {
        return root;
    }
    if (strcmp(title, root->doc.title) < 0) {
        return searchBST(root->left, title);
    } else {
        return searchBST(root->right, title);
    }
}

void inorderTraversal(BST* tree, void (*func)(TreeNode*)) {
    if (tree != NULL && tree->root != NULL) {
        inorderTraversalHelper(tree->root, func);
    }
}

static void inorderTraversalHelper(TreeNode* node, void (*func)(TreeNode*)) {
    if (node != NULL) {
        inorderTraversalHelper(node->left, func);
        func(node);
        inorderTraversalHelper(node->right, func);
    }
}

void print_document_info(TreeNode* node) {
    if (node != NULL) {
        printf("ID: %d, Título: %s, Palabras: %d, Caracteres: %d\n",
               node->doc.id, node->doc.title, node->doc.word_count, node->doc.char_count);
    }
}

void freeBSTNodes(TreeNode* node) {
    if (node != NULL) {
        freeBSTNodes(node->left);
        freeBSTNodes(node->right);
        free(node->doc.title);  // Asegurando que el título es una cadena dinámica
        free(node);
    }
}