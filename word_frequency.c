#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_frequency.h"
#include "binary_tree.h"


unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % 1000;
}

WordFrequency* collectWords(WordFrequency **map) {
    WordFrequency *allWords = NULL, *last = NULL;
    for (int i = 0; i < 1000; ++i) {
        WordFrequency *current = map[i];
        while (current) {
            WordFrequency *newWord = (WordFrequency *)malloc(sizeof(WordFrequency));
            strcpy(newWord->word, current->word);
            newWord->count = current->count;
            newWord->next = NULL;

            if (!allWords) {
                allWords = newWord;
                last = allWords;
            } else {
                last->next = newWord;
                last = newWord;
            }
            current = current->next;
        }
    }
    return allWords;
}

void insertWord(WordFrequency **map, const char *word, int docId) {
    unsigned int index = hash(word);
    WordFrequency *wf = map[index];
    while (wf) {
        if (strcmp(wf->word, word) == 0) {
            if (wf->docId != docId) {
                wf->docCount++;
                wf->docId = docId;
            }
            wf->count++;
            return;
        }
        wf = wf->next;
    }

    wf = (WordFrequency *)malloc(sizeof(WordFrequency));
    strcpy(wf->word, word);
    wf->count = 1;
    wf->docCount = 1; // Inicializar docCount a 1
    wf->docId = docId; // Guardar el docId
    wf->next = map[index];
    map[index] = wf;
}

void findFrequentWords(int id) {
    char filename[256];
    sprintf(filename, "Libros/%d.txt", id); // Asegúrate de  que esta ruta sea correcta

   FILE *file = fopen(filename, "r");
    if (!file) {
      printf("Error opening file: %s\n", filename); // Esto imprimirá el nombre del archivo que no se pudo abrir
    return;
}

    WordFrequency *map[1000] = {0}; // Hash map

    char word[256];
    while (fscanf(file, " %255s", word) == 1) {
        // Convertir cada palabra a minúsculas
        for (int i = 0; word[i]; ++i) {
            word[i] = tolower(word[i]);
        }

        // Insertar cada palabra en el mapa hash
        insertWord(map, word,id);
    }

    fclose(file);

    // Mostrar las palabras más frecuentes
    showMostFrequentWords(map, 10); // Asumiendo que quieres mostrar las 10 palabras más frecuentes
}


// Función para ordenar las palabras por frecuencia
void sortWordsByFrequency(WordFrequency **allWords) {
    WordFrequency *i, *j;
    int tempCount;
    char tempWord[256];

    for (i = *allWords; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->count < j->count) {
                // Intercambiar conteo
                tempCount = i->count;
                i->count = j->count;
                j->count = tempCount;

                // Intercambiar palabras
                strcpy(tempWord, i->word);
                strcpy(i->word, j->word);
                strcpy(j->word, tempWord);
            }
        }
    }
}

  // Función para mostrar las N palabras más frecuentes
void showMostFrequentWords(WordFrequency **map, int N) {
    printf("Por favor espere, procesando palabras...\n");
    WordFrequency *allWords = collectWords(map);
    sortWordsByFrequency(&allWords);

    WordFrequency *current = allWords;
    int count = 0;

    printf("Las %d palabras más frecuentes son:\n", N);
    while (current != NULL && count < N) {
        printf("%s: %d times\n", current->word, current->count);
        current = current->next;
        count++;
    }

    // Liberar la memoria de allWords cuando hayas terminado
    while (allWords != NULL) {
        WordFrequency *temp = allWords;
        allWords = allWords->next;
        free(temp);
    }
}

// Función para calcular la relevancia de cada palabra
void calculateRelevance(WordFrequency **map, int totalDocs) {
    for (int i = 0; i < 1000; ++i) {
        WordFrequency *current = map[i];
        while (current) {
            current->relevance = (current->count) * log((double)totalDocs / current->docCount);
            current = current->next;
        }
    }
}

// Función para mostrar las N palabras más relevantes
void showMostRelevantWords(WordFrequency **map, int totalDocs, int N) {
    calculateRelevance(map, totalDocs); // Calcular la relevancia antes de mostrar las palabras
    WordFrequency *allWords = collectWords(map);
    sortWordsByRelevance(&allWords); // Asumiendo que tienes una función para ordenar por relevancia

    WordFrequency *current = allWords;
    int count = 0;

    printf("Las 10 palabras más relevantes son:\n");
    while (current != NULL && count < N) {
        printf("%s: %f\n", current->word, current->relevance);
        current = current->next;
        count++;
    }

    // Liberar la memoria de allWords cuando hayas terminado
    while (allWords != NULL) {
        WordFrequency *temp = allWords;
        allWords = allWords->next;
        free(temp);
    }
}

// Función para ordenar las palabras por relevancia
void sortWordsByRelevance(WordFrequency **allWords) {
    WordFrequency *i, *j;
    double tempRelevance;
    char tempWord[256];

    for (i = *allWords; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->relevance < j->relevance) {
                // Intercambiar relevancia
                tempRelevance = i->relevance;
                i->relevance = j->relevance;
                j->relevance = tempRelevance;

                // Intercambiar palabras
                strcpy(tempWord, i->word);
                strcpy(i->word, j->word);
                strcpy(j->word, tempWord);
            }
        }
    }
}


double getWordRelevance(WordFrequency **map, const char *word, int docId) {
    unsigned int index = hash(word); // Asumiendo que tienes una función hash
    WordFrequency *wf = map[index];
    while (wf) {
        if (strcmp(wf->word, word) == 0 && wf->docId == docId) {
            return wf->relevance;
        }
        wf = wf->next;
    }
    return 0;
}

