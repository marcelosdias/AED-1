#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *p, int inicio, int final);
void merge(int *p, int inicio, int meio, int final);
void printArray(int *p, int size);

int main()
{
    int arr[] = { 5, 4, 3, 2, 1};
 
    printArray(arr, 5);
 
    mergeSort(arr, 0, 4);
 
    printArray(arr, 5);
    return 0;
}

void mergeSort(int *p, int inicio, int final) {
    if (inicio < final) {

        int meio = inicio + (final - inicio) / 2;
 
        mergeSort(p, inicio, meio);
        mergeSort(p, meio + 1, final);
 
        merge(p, inicio, meio, final);
    }
}

void merge(int *p, int inicio, int meio, int final) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = final - meio;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = p[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = p[meio + 1 + j];
 
    i = 0; 
    j = 0; 
    k = inicio; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            p[k] = L[i];
            i++;
        }
        else {
            p[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        p[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        p[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int *p, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", p[i]);
    printf("\n");
}
