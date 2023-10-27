#include <stdio.h>
#include "binary_tree.h"
#include "file_processing.h"
#include "search_functions.h"
#include "word_frequency.h"
extern int totalDocs;
WordFrequency *map[1000] = {0}; // Hash map

int main() {
    Node* root = NULL;
    int option;

      do {
        printf("0. Salir\n");
        printf("1. Cargar documentos\n");
        printf("2. Mostrar documentos\n");
        printf("3. Buscar libro por título\n");
        printf("4. Palabras con mayor frecuencia\n");
        printf("5. Palabras más relevantes\n");
        printf("6. Buscar por palabra\n");
        printf("7. Mostrar palabra en su contexto dentro del libro\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);
        getchar(); // consume newline

        switch (option) {
            case 0:
                printf("Saliendo del programa.\n");
                break;
            case 1:
                root = loadBooksFromFolder(root);
                break;
            case 2:
                printTree(root);
                break;
            case 3:
                searchBookByTitle(root);
                break;
            case 4:
          {
              int id;
              printf("Ingrese el ID del libro: ");
              scanf("%d", &id);
              getchar(); // consume newline

              if (idExists(root, id)) {
                  findFrequentWords(id);
              } else {
                  printf("ID no encontrado.\n");
              }
          }
                break;
          case 5:
          {
              char title[256];
              printf("Ingrese el título del libro: ");
              fgets(title, 256, stdin);
              title[strcspn(title, "\n")] = 0; // Remove newline character

              int id = findBookIdByTitle(root, title);
              if (id != -1) {
                  showMostRelevantWords(id, totalDocs, 10);
              } else {
                  printf("Título no encontrado.\n");
              }
          }
                break;
          case 6:
          {
              char word[256];
              printf("Ingrese la palabra a buscar: ");
              scanf("%s", word);
              searchWordInDocuments(word, root); // Eliminado el argumento map
              break;
          }
          case 7:
          {
              char title[256], word[256];
              printf("Ingrese el título del libro: ");
              fgets(title, 256, stdin);
              title[strcspn(title, "\n")] = 0; // Remove newline character

              printf("Ingrese la palabra a buscar: ");
              scanf("%s", word);

              showWordInContext(title, word, root);
              break;
          }
        }
    } while (option != 0);

    return 0;
}