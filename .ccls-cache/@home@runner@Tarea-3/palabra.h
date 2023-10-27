#ifndef PALABRA_H
#define PALABRA_H

#include <stdlib.h>

typedef struct Palabra {
    char *string;
    int count;
} Palabra;

Palabra* createPalabra(char *string);
void incrementCount(Palabra *palabra);

#endif // PALABRA_H