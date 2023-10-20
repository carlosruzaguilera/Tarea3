// util.c
#include "util.h"
#include <string.h>

long long stringHash(const void *key) {
    long long hash = 5381;
    const char *ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash = ((hash << 5) + hash) + *ptr;  // hash * 33 + c
    }
    return hash;
}

int stringEqual(const void *key1, const void *key2) {
    return strcmp((const char *)key1, (const char *)key2) == 0;
}
