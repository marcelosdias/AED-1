#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *realloc2(void *pont, size_t newSize, int size);

int main () {
    return 0;
}

void *realloc2(void *pont, size_t newSize, int size) {
    void *p;

    p = malloc(newSize);

    memcpy(p, pont, size);

    free(pont);

    return p;
}

