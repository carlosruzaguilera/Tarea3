# Tarea3
Proyecto de Biblioteca Virtual
Descripción
Este proyecto es una aplicación de consola que permite a los usuarios interactuar con una biblioteca virtual. Los usuarios pueden cargar documentos (libros), buscar libros por título, encontrar palabras clave dentro de los libros y realizar varias otras operaciones relacionadas con el análisis de texto.

Funcionalidades
Cargar documentos: Carga libros desde un directorio especificado.
Mostrar documentos: Muestra todos los libros cargados con sus detalles.
Buscar libro por título: Busca un libro específico por su título.
Palabras con mayor frecuencia: Muestra las palabras más frecuentes en un libro específico.
Palabras más relevantes: Muestra las palabras más relevantes de un libro específico.
Buscar por palabra: Busca libros que contienen una palabra específica y muestra su relevancia.
Mostrar palabra en su contexto dentro del libro: Muestra las apariciones de una palabra específica dentro de un contexto en un libro específico.
Estructura de Archivos
main.c: Contiene la función principal que ejecuta la aplicación.
binary_tree.h y binary_tree.c: Contienen funciones relacionadas con la manipulación de árboles binarios, que se utilizan para almacenar información sobre los libros.
file_processing.h y file_processing.c: Contienen funciones para cargar libros desde un directorio.
search_functions.h y search_functions.c: Contienen funciones para buscar libros y palabras dentro de los libros.
word_frequency.h y word_frequency.c: Contienen funciones para analizar la frecuencia y relevancia de las palabras dentro de los libros.
Compilación y Ejecución
Para compilar el proyecto, debe ejecutrse en replit y correrlo.

Problemas Conocidos

Función 6: Buscar por palabra
Descripción del problema:
Esta función está diseñada para buscar una palabra específica en todos los documentos y mostrar su relevancia. Sin embargo, actualmente no está funcionando como se espera.

Posibles causas:

La función getWordRelevance podría no estar calculando correctamente la relevancia de la palabra.
Podría haber un problema con la función hash o con la inserción de palabras en el mapa hash.
Podría haber un problema con la tokenización de las palabras en los documentos.

Función 7: Mostrar palabra en su contexto dentro del libro
Descripción del problema:
Esta función debería mostrar una palabra específica en su contexto dentro de un libro específico, pero no está dando los resultados esperados.

Posibles causas:

Podría haber un problema con la manera en que se están leyendo los archivos o las líneas dentro de los archivos.
La función podría no estar encontrando correctamente la palabra dentro de las líneas de texto.
Podría haber un problema con la entrada del usuario, como el título del libro o la palabra a buscar.
Soluciones Potenciales
Para ambos problemas, considera revisar y depurar cuidadosamente cada parte de las funciones, asegurándote de que cada componente (como la lectura de archivos, la tokenización de palabras, el cálculo de relevancia, etc.) esté funcionando correctamente. También podrías considerar agregar más mensajes de error o de debug para ayudarte a identificar dónde podrían estar ocurriendo los problemas.

este trabajo fue realizado de manera individual, como fui solo en este trabajo me calificaria con un 6.0 ya que aunque en el programa no funcionaron todas las opciones, la gran mayoria si lo hacen.
