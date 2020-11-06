#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *retiraRepetidos(int *p, int *tamanho);
int *insertionSort(int *p, int tamanho);

int main() {
    int tamanho, *p, i;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    p = (int*)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {
        printf("[%d]: ", i+1);
        scanf("%d", &p[i]);
    }

    p = insertionSort(p, tamanho); // Ordena os números, tornando mais fácil a comparação com o próximo número do vetor
    p = retiraRepetidos(p, &tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d\n", p[i]);
    }


    free(p);

    return 0;
}

int *insertionSort(int *p, int tamanho) {
    int i, j, tmp;

    for (j = 1; j < tamanho; j++) {
        i = j-1;
        tmp = p[j];

        while ( (i>=0) && (tmp < p[i]) ) {
            p[i+1] = p[i];
            i--;
        }

        p[i+1] = tmp;
    }
    return p;
}

int *retiraRepetidos(int *p, int *tamanho) {
    int i, j, novoTamanho = 0, *q;

    for (i = 0; i < *tamanho; i++) {
        if (i == (*tamanho-1)) {
            if (p[i-1] != p[i]) {
                novoTamanho++;
            }
        } else {
            if (p[i] != p[i+1]) {
                novoTamanho++;
            }
        }
    }
    
    q = (int*)malloc(novoTamanho * sizeof(int)); 

    for(i = 0, j = 0; i < *tamanho; i++) { // O vetor se encontra no seguinte formato, [1,1,2], por estar ordenado, sempre que o proximo valor for diferente acabou a repetição
        if (i == (*tamanho-1)) { // Teste para sabe se chegou no último elemento, evitando acessar um endereço não alocado
            if (p[i-1] != p[i]) {
                q[j++] = p[i];
            }
        }
        else {
            if (p[i] != p[i+1]) {
                q[j++] = p[i];
            }
        }
    }

    *tamanho = novoTamanho;

    free(p);

    return q;
}