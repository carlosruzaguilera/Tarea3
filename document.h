#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct Document {
    int id;  // Agregar esta línea
    char *title;
    int word_count;
    int char_count;
} Document;

#endif // DOCUMENT_H
