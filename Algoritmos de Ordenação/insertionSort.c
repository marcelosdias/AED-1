#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *p, int n);

int main() {
    int vetor[] = { 5, 4, 3, 2, 1 }, i;

    for (i = 0; i < 5; i++) 
        printf("%d ", vetor[i]);

    insertionSort(vetor, 5);

    printf("\n");

    for (i = 0; i < 5; i++) 
        printf("%d ", vetor[i]);

    printf("\n");

    return 0;
}

void insertionSort(int *p, int n) {
    int i, j, aux;

    for (j = 1; j < n; j++) {
        i = j - 1;
        aux = p[j];

        while ((i >= 0) && (aux < p[i])) {
            p[i+1] = p[i];
            i--;
        }
        p[i+1] = aux;
    }
}