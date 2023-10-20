// palabra.h
#ifndef PALABRA_H
#define PALABRA_H

#include <stdlib.h>

// Definición de la estructura Palabra
typedef struct Palabra {
    char *string;  // El string de la palabra
    int count;     // Número de ocurrencias
    // ... (otras posibles propiedades, como una lista de posiciones)
} Palabra;

// Funciones para trabajar con Palabra
Palabra* createPalabra(char *string);
void incrementCount(Palabra *palabra);
// ... (otras posibles funciones, como obtener el string o el count)

#endif // PALABRA_H