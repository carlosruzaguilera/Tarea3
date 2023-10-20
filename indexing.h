#ifndef INDEXING_H
#define INDEXING_H

#include "bst.h"  // Incluye la definición de la estructura BST y TreeNode

void initialize_indexing();
void load_document(const char *file_path);
void load_all_documents(const char *directory_path);
void display_documents();
void clean_indexing();

#endif // INDEXING_H