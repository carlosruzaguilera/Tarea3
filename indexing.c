#include "indexing.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Instancia global de BST
BST *global_bst = NULL;
// Variable global para mantener un contador de documentos
int document_count = 0;


void initialize_indexing() {
    global_bst = createBST();  // Crear una nueva instancia de BST
}


void load_document(const char *file_path) {
    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    Document doc;
    doc.id = document_count++;  // Asigna un ID único y luego incrementa el contador

    char line[256];
    while (fgets(line, sizeof(line), file_ptr) != NULL) {
        // Buscar la línea que comienza con "Title:"
        if (strncmp(line, "Title: ", 7) == 0) {
            // Eliminar el "Title: " del inicio y el salto de línea al final
            char *title = line + 7;
            title[strcspn(title, "\n")] = '\0';
            doc.title = strdup(title);
            if (doc.title == NULL) {  // Verificar si strdup fue exitoso
                perror("Error al duplicar el título del documento");
                fclose(file_ptr);  // Asegúrate de cerrar el archivo
                return;
            }
            break;  // Salir del bucle una vez que encontramos el título
        }
    }

    // Verificar si se encontró el título
    if (doc.title == NULL) {
        fprintf(stderr, "Error al leer el título del documento\n");
        fclose(file_ptr);  // Asegúrate de cerrar el archivo
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
    global_bst->root = insert(global_bst->root, doc);

    // Mensaje de depuración para confirmar que el documento se cargó correctamente
    printf("Documento cargado: %s (Palabras: %d, Caracteres: %d)\n", doc.title, doc.word_count, doc.char_count);

    fclose(file_ptr);
}


void load_all_documents(const char *directory_path) {
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Verificar si la entrada es un archivo regular y tiene extensión .txt
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != NULL) {
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
            printf("Cargando documento desde: %s\n", file_path);
            load_document(file_path);
        } else {
            printf("Entrada no procesada: %s (no es un archivo regular o no tiene extensión .txt)\n", entry->d_name);
        }
    }

    closedir(dir);
}

void display_documents() {
    // Recorrer el árbol binario en orden y mostrar información de documentos
    inorderTraversal(global_bst, print_document_info);
}

void clean_indexing() {
  // Liberar la memoria del árbol binario y otros recursos
  cleanupBST(global_bst);  // Llama a cleanupBST para liberar la memoria del BST
  global_bst = NULL;
}

void display_documents_wrapper() {
    display_documents();
}
