// searching.h
#ifndef SEARCHING_H
#define SEARCHING_H

#include "indexing.h"

void searchBookByTitle(BST *docTree, char *title);
void searchBooksByWord(BST *docTree, char *word);
void displayWordContext(Document *doc, char *word);

#endif // SEARCHING_H
