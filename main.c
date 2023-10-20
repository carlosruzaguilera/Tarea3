// main.c
#include "interface.h"

int main() {
    // Inicializa el árbol binario de búsqueda (BST) para almacenar los documentos.
    BST *docTree = createBST();

    // Llama a la función handleUserInput en interface.c para coordinar la ejecución del programa.
    handleUserInput(docTree);

    // Libera la memoria utilizada por el BST y otros recursos antes de salir.
    // (Asegúrate de implementar y llamar a una función de limpieza adecuada para liberar la memoria.)
    cleanupBST(docTree);

    return 0;
}
