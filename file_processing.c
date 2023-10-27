#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "file_processing.h"
#include "binary_tree.h"

int totalDocs = 0;

Node* loadBooksFromFolder(Node* root) {
    char folderName[256];
    printf("Enter the folder name: ");
    scanf("%s", folderName);

    DIR *d;
    struct dirent *dir;
    d = opendir(folderName);

    if (d) {
              while ((dir = readdir(d)) != NULL) {
                if (strstr(dir->d_name, ".txt")) {
                    totalDocs++; // Asegurarse de que sea un archivo txt
                char filepath[512];
                sprintf(filepath, "%s/%s", folderName, dir->d_name);

              FILE *file = fopen(filepath, "r");
              if (file) {
                  char line[512];
                  char title[256] = "";
                  int wordCount = 0;
                  int charCount = 0;

                  while (fgets(line, sizeof(line), file)) {
                      if (strstr(line, "Title:")) {
                          sscanf(line, "Title: %[^\n]", title);
                      }

                      charCount += strlen(line);

                      // Contar palabras
                      char *token = strtok(line, " \t\r\n");
                      while (token != NULL) {
                          wordCount++;
                          token = strtok(NULL, " \t\r\n");
                      }
                  }
                  fclose(file);

                  if (strlen(title) > 0) {
                      int id = atoi(dir->d_name);
                      root = insert(root, id, title, wordCount, charCount);
                      printf("Loaded: ID %d\n", id);
                  }
                }
            }
        }
        closedir(d);
    }

    return root;
}
