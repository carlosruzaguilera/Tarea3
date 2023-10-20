// analysis.h
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "indexing.h"

void calculateMostFrequentWords(Document *doc);
void calculateMostRelevantWords(BST *docTree, Document *doc);

#endif // ANALYSIS_H
