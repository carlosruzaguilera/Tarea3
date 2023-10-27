#include "search_functions.h"
#include "word_frequency.h"
#include <string.h>
#include <stdio.h>

void searchBookByTitle(Node* root) {
    char keywords[256];
    printf("Enter keywords separated by spaces: ");
    fgets(keywords, 256, stdin);
    keywords[strcspn(keywords, "\n")] = 0; // Remove newline character

    printf("Books matching the keywords:\n");
    searchTreeForKeywords(root, keywords);
}

void searchTreeForKeywords(Node* root, char* keywords) {
    if (root != NULL) {
        searchTreeForKeywords(root->left, keywords);

        char keywordsCopy[256];
        strcpy(keywordsCopy, keywords);

        char* token = strtok(keywordsCopy, " ");
        int isMatch = 1;
        while (token != NULL) {
            if (strstr(root->title, token) == NULL) {
                isMatch = 0;
                break;
            }
            token = strtok(NULL, " ");
        }

        if (isMatch) {
            printf("%s\n", root->title);
        }

        searchTreeForKeywords(root->right, keywords);
    }
}

int findBookIdByTitle(Node* root, const char* title) {
    if (root != NULL) {
        if (strcasecmp(root->title, title) == 0) {
            return root->id;
        }
        int leftSearch = findBookIdByTitle(root->left, title);
        if (leftSearch != -1) {
            return leftSearch;
        }
        return findBookIdByTitle(root->right, title);
    }
    return -1; // Retorna -1 si el título no se encuentra
}


void searchWordInDocuments(const char *word, Node *root) {
    if (root != NULL) {
        searchWordInDocuments(word, root->left);

        // Asegúrate de que getWordRelevance esté implementada correctamente
        double relevance = getWordRelevance(word, root->id); 

        if (relevance > 0) {
            printf("ID: %d, Title: %s, Relevance: %f\n", root->id, root->title, relevance);
        }

        searchWordInDocuments(word, root->right);
    }
}

void showWordInContext(const char *title, const char *word, Node *root) {
    int id = findBookIdByTitle(root, title);
    if (id == -1) {
        printf("Título no encontrado.\n");
        return;
    }

    char filename[256];
    sprintf(filename, "Libros/%d.txt", id); // Asegúrate de que esta ruta sea correcta

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error al abrir el archivo: %s\n", filename);
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char *pos = strstr(line, word);
        if (pos) {
            printf("Contexto: %s", line); // Imprime la línea completa donde se encontró la palabra
        }
    }

    fclose(file);
}