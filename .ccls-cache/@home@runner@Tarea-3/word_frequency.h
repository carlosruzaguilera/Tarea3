#ifndef WORD_FREQUENCY_H
#define WORD_FREQUENCY_H

typedef struct WordFrequency {
    char word[256];
    int count;
    int docCount; // Número de documentos en los que aparece la palabra
    double relevance; // Relevancia de la palabra
    int docId; // Agrega esta línea
    struct WordFrequency* next;
} WordFrequency;

// Función para insertar una palabra en el mapa hash
void insertWord(WordFrequency **map, const char *word, int docId);

// Función para encontrar y mostrar las palabras más frecuentes en un archivo
void findFrequentWords(int id);

// Función para recolectar todas las palabras en una lista
WordFrequency* collectWords(WordFrequency **map);

// Función para ordenar las palabras por frecuencia
void sortWordsByFrequency(WordFrequency **allWords);

// Función para mostrar las N palabras más frecuentes
void showMostFrequentWords(WordFrequency **map, int N);

// Función para mostrar las N palabras más relevantes
void showMostRelevantWords(WordFrequency **map, int totalDocs, int N);

void sortWordsByRelevance(WordFrequency **allWords);

#endif // WORD_FREQUENCY_H
