#include "interface.h"
#include "indexing.h"  // Asegúrate de incluir los encabezados necesarios
#include "searching.h"
#include "analysis.h"
#include <stdio.h>
#include <string.h>

void handleUserInput(BST *docTree) {
    int choice;
    char input[256];  // Asumiendo que 256 caracteres es suficiente para la entrada del usuario

    do {
        printf("Menú:\n");
        printf("1. Cargar documentos\n");
        printf("2. Mostrar documentos\n");
        printf("3. Buscar un libro por título\n");
        printf("4. Palabras con mayor frecuencia\n");
        printf("5. Palabras más relevantes\n");
        printf("6. Buscar por palabra\n");
        printf("7. Mostrar palabra en su contexto dentro del libro\n");
        printf("0. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Llamar a la función para cargar documentos
                printf("Ingrese la ruta del directorio donde están los documentos: ");
                scanf("%s", input);
                load_all_documents(input);
                break;
            case 2:
                // Llamar a la función para mostrar documentos
                display_documents_wrapper();
                break;
            case 3:
              // Buscar un libro por título
              printf("Ingrese el título del libro que desea buscar: ");
              getchar();  // Consume el carácter de nueva línea dejado por scanf
              fgets(input, sizeof(input), stdin);  // Cambia scanf por fgets
              input[strcspn(input, "\n")] = '\0';  // Elimina el carácter de nueva línea
              searchBookByTitle(docTree, input);
              break;
            case 4:
                // Palabras con mayor frecuencia
                printf("Ingrese el ID del libro: ");
                scanf("%255s", input);  // Asumiendo que el ID es una cadena
                Document doc;  // Asumiendo que tienes una forma de obtener el documento por ID
                // ... (código para obtener el documento por ID)
                calculateMostFrequentWords(&doc);
                break;
          case 5:
          // Palabras más relevantes
          printf("Ingrese el título del libro: ");
          getchar();  // Consume el carácter de nueva línea dejado por scanf
          fgets(input, sizeof(input), stdin);  // Cambia scanf por fgets
          input[strcspn(input, "\n")] = '\0';  // Elimina el carácter de nueva línea
          // ... (código para obtener el documento por título)
          calculateMostRelevantWords(docTree, &doc);
          break;
            case 6:
                // Buscar por palabra
                printf("Ingrese la palabra: ");
                scanf("%255s", input);
                searchBooksByWord(docTree, input);
                break;
          case 7:
          // Mostrar palabra en su contexto dentro del libro
          printf("Ingrese el título del libro: ");
          getchar();  // Consume el carácter de nueva línea dejado por scanf
          fgets(input, sizeof(input), stdin);  // Cambia scanf por fgets
          input[strcspn(input, "\n")] = '\0';  // Elimina el carácter de nueva línea
          char word[256];
          printf("Ingrese la palabra a buscar: ");
          scanf("%255s", word);
          // ... (código para obtener el documento por título)
          displayWordContext(&doc, word);
          break;
            case 0:
                printf("Saliendo...\n");
                clean_indexing();  // Asegúrate de liberar cualquier memoria antes de salir
                break;
            default:
                printf("Elección inválida. Intente de nuevo.\n");
                break;
        }
    } while (choice != 0);
}
