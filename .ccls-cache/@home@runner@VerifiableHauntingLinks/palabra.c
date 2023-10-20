// palabra.c
#include "palabra.h"
#include <string.h>

// Función para crear una nueva Palabra
Palabra* createPalabra(char *string) {
    Palabra *palabra = (Palabra *)malloc(sizeof(Palabra));
    if (palabra == NULL) {
        exit(1);  // Salir con un código de error
    }
    palabra->string = strdup(string);
    if (palabra->string == NULL) {
        free(palabra);
        exit(1);  // Salir con un código de error
    }
    palabra->count = 1;
    // ... (inicialización de otras posibles propiedades)
    return palabra;
}

// Función para incrementar el contador de ocurrencias
void incrementCount(Palabra *palabra) {
    palabra->count++;
}

// ... (otras posibles funciones, como obtener el string o el count)
