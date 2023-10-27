#ifndef SEARCHING_H
#define SEARCHING_H

#include "indexing.h"

void searchBookByTitle(BST *docTree, const char *title);
void searchBooksByWord(BST *docTree, const char *word);
void displayWordContext(Document *doc, const char *word);
int wordExistsInDocument(Document* doc, const char* word);
char* getWordContext(Document* doc, const char* word);
#endif // SEARCHING_H