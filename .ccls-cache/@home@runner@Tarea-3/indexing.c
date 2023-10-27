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

int filter(const struct dirent *entry) {
    // Esta función de filtro se usará con scandir para listar solo los archivos .txt
    return strstr(entry->d_name, ".txt") != NULL;
}

void load_document(const char *file_path) {
    printf("Cargando documento: %s\n", file_path);  // Agrega esta línea
    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        perror("Error al abrir el archivo");
        printf("No se pudo abrir el archivo: %s\n", file_path);  // Agregar mensaje de depuración
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

    // Si no encontramos el título, cerramos el archivo y retornamos
    if (doc.title == NULL) {
        fprintf(stderr, "Error al leer el título del documento\n");
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
    global_bst->root = insert(global_bst->root, doc);

    // Mensaje de depuración para confirmar que el documento se cargó correctamente
    printf("Documento cargado: %s (Palabras: %d, Caracteres: %d)\n", doc.title, doc.word_count, doc.char_count);  // Esta línea ya estaba, pero es útil para la depuración

    fclose(file_ptr);
    printf("Documento procesado: %s\n", file_path);  // Agrega esta línea
}


void load_all_documents(const char *directory_path) {
    printf("Entrando a load_all_documents\n");  // Agrega esta línea
    struct dirent **namelist;
    int n;

    n = scandir(directory_path, &namelist, filter, alphasort);
    if (n == -1) {
        perror("Error al listar los archivos del directorio");
        return;
    }

    printf("scandir encontró %d archivos .txt\n", n);  // Esta línea ya estaba, pero es útil para la depuración

    for (int i = 0; i < n; i++) {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, namelist[i]->d_name);
        printf("Procesando archivo: %s\n", file_path);  // Esta línea ya estaba, pero es útil para la depuración
        load_document(file_path);
        free(namelist[i]);  // Liberar la memoria asignada por scandir
    }
    free(namelist);  // Liberar la lista de nombres
    printf("Saliendo de load_all_documents\n");  // Agrega esta línea
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
