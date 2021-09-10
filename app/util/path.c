#include "path.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *path_join(const char *parent, const char *basename) {
    unsigned int parentlen = strlen(parent);
    if (parentlen && parent[parentlen - 1] == PATH_SEPARATOR) {
        parentlen -= 1;
    }
    char *joined = calloc(parentlen + 1 + strlen(basename) + 1, sizeof(char));
    sprintf(joined, "%.*s%c%s", parentlen, parent, PATH_SEPARATOR, basename);
    return joined;
}

void path_join_to(char *dest, size_t maxlen, const char *parent, const char *basename) {
    unsigned int parentlen = strlen(parent);
    if (parentlen && parent[parentlen - 1] == PATH_SEPARATOR) {
        parentlen -= 1;
    }
    snprintf(dest, maxlen, "%.*s%c%s", parentlen, parent, PATH_SEPARATOR, basename);
}