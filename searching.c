// searching.c
#include "searching.h"
#include <stdio.h>
#include <string.h>

void searchBookByTitle(BST *docTree, char *title) {
    Document *doc = (Document *) searchBST(docTree, title);
    if (doc != NULL) {
      printf("Title: %s, Word Count: %d, Character Count: %d\n", doc->title, doc->word_count, doc->char_count);
    } else {
        printf("No document found with title: %s\n", title);
    }
}

void searchBooksByWord(BST *docTree, char *word) {
    // Implementa una función de recorrido en el BST docTree para buscar la palabra en cada documento.
    // Si la palabra se encuentra en un documento, imprime el título del documento y otros detalles relevantes.
    // Esta función podría necesitar una función auxiliar recursiva.
}

void displayWordContext(Document *doc, char *word) {
    // Implementa una función para buscar la palabra en el documento y mostrar el contexto en el que aparece.
    // Puedes necesitar una función para buscar la palabra en el BST doc->wordTree y otra para recuperar el contexto del archivo.
}

