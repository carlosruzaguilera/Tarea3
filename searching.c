// searching.c
#include "searching.h"
#include <stdio.h>
#include <string.h>

void searchBookByTitle(BST *docTree, const char *title) {
    Document *doc = (Document *) searchBST(docTree, title);
    if (doc != NULL) {
      printf("Title: %s, Word Count: %d, Character Count: %d\n", doc->title, doc->word_count, doc->char_count);
    } else {
        printf("No document found with title: %s\n", title);
    }
}

void searchWordInNode(TreeNode* node, const char *word) {
    if (node != NULL) {
        searchWordInNode(node->left, word);

        // Suponiendo que tienes una función wordExistsInDocument que verifica
        // si una palabra existe en un documento.
        if (wordExistsInDocument(&node->doc, word)) {
            printf("La palabra '%s' se encontró en el documento: %s\n", word, node->doc.title);
        }

        searchWordInNode(node->right, word);
    }
}

void searchBooksByWord(BST *docTree, const char *word) {
    if (docTree != NULL) {
        searchWordInNode(docTree->root, word);
    }
}

void displayWordContext(Document *doc, const char *word) {
    if (doc != NULL) {
        // Suponiendo que tienes una función getWordContext que retorna
        // el contexto de una palabra en un documento.
        char* context = getWordContext(doc, word);
        if (context != NULL) {
            printf("Contexto de la palabra '%s' en el documento %s: %s\n", word, doc->title, context);
            free(context);  // Libera la memoria si getWordContext aloja memoria dinámicamente.
        } else {
            printf("La palabra '%s' no se encontró en el documento: %s\n", word, doc->title);
        }
    }
}

// Suponiendo que esta función verifica si una palabra existe en un documento
int wordExistsInDocument(Document* doc, const char* word) {
    // Asumiendo que tienes una forma de buscar palabras en el documento.
    // Esta es una implementación ficticia y deberás reemplazarla con tu propia lógica.

    // Por ejemplo, si tienes un árbol binario de búsqueda o una tabla hash
    // para almacenar las palabras en el documento, podrías buscar la palabra en esa estructura.

    // Retorna 1 si la palabra existe, 0 en caso contrario.
    return 0; 
}

// Suponiendo que esta función obtiene el contexto de una palabra en un documento
char* getWordContext(Document* doc, const char* word) {
    // Asumiendo que tienes una forma de obtener el contexto de una palabra en el documento.
    // Esta es una implementación ficticia y deberás reemplazarla con tu propia lógica.

    // Por ejemplo, podrías buscar la palabra en el documento y luego retornar
    // una cadena que contiene la palabra y algunas palabras antes y después de ella.

    // Esta función retorna NULL si la palabra no se encuentra o si ocurre un error.
    return NULL;
}