#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *p, int tam);

int main() {
    int vetor[] = { 5, 4, 3, 2, 1 }, i;

    for (i = 0; i < 5; i++)
        printf("%d ", vetor[i]);

    printf("\n");

    selectionSort(vetor, 5);

    for (i = 0; i < 5; i++)
        printf("%d ", vetor[i]);

    printf("\n");

    return 0;
}

void selectionSort(int *p, int tam) {
    int i, j, min, aux;

    for (i = 0; i < (tam-1); i++) {
        min = i;

        for (j = i+1; j < tam; j++) {
            if (p[j] < p[i]) 
                min = j;
        }

        if (i != min) {
            aux = p[i];
            p[i] = p[min];
            p[min] = aux;
        }
    }
}