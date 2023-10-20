#include "indexing.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Árbol binario para almacenar documentos indexados
TreeNode *document_tree = NULL;

void initialize_indexing() {
    document_tree = NULL;  // Inicializa el árbol a NULL
}

void load_document(const char *file_path) {
    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    Document doc;
    char title[256];
    // Suponiendo que el título está en la primera línea del archivo
    if (fgets(title, sizeof(title), file_ptr) != NULL) {
        // Eliminar el salto de línea al final del título
        title[strcspn(title, "\n")] = '\0';
        doc.title = strdup(title);
    } else {
        perror("Error al leer el título del documento");
        fclose(file_ptr);
        return;
    }

    int word_count = 0, char_count = 0;
    char word[256];
    while (fscanf(file_ptr, "%255s", word) != EOF) {
        word_count++;
        char_count += strlen(word);
    }

    doc.word_count = word_count;
    doc.char_count = char_count;

    // Insertar el documento en el árbol binario
    document_tree = insert(document_tree, doc);

    fclose(file_ptr);
}

void load_all_documents(const char *directory_path) {
    // ... (código existente)
}

void display_documents() {
    // Recorrer el árbol binario en orden y mostrar información de documentos
    inorder_traversal(document_tree);
}

void clean_indexing() {
    // Liberar la memoria del árbol binario y otros recursos
    free_tree(document_tree);
    document_tree = NULL;
}