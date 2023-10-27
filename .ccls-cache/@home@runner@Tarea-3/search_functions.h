#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

#include "binary_tree.h"

void searchBookByTitle(Node* root);
void searchTreeForKeywords(Node* root, char* keywords);
void searchWordInDocuments(const char *word, Node *root);
void showWordInContext(const char *title, const char *word, Node *root);


int findBookIdByTitle(Node* root, const char* title);

#endif
