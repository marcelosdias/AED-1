#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *realloc2(void *pont, size_t newSize);

int main () {
}

void *realloc2(void *pont, size_t newSize) {
    void *p;

    p = malloc(newSize);

    memcpy(p, pont, newSize);

    free(pont);

    return p;
}

