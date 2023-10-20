#include "interface.h"
#include <stdio.h>

void handleUserInput(BST *docTree) {
    int choice;
    do {
        printf("Menú:\n");
        printf("1. Cargar documentos\n");
        printf("2. Mostrar documentos\n");
        // ... otras opciones
        printf("0. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Llamar a la función para cargar documentos
                break;
            case 2:
                // Llamar a la función para mostrar documentos
                break;
            // ... otros casos
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Elección inválida. Intente de nuevo.\n");
                break;
        }
    } while (choice != 0);
}
