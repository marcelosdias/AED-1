#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **criaMatriz(int nLin, int nCol);
void leiaMatriz(int **matriz, int nLin, int nCol);
void imprimeMatriz(int **matriz, int nLin, int nCol);
int somaMatriz(int **matriz, int nLin, int nCol);
int *colunaMatriz(int **matriz, int nLin, int nCol, int colunaSelecionada);
void imprimeVetor (int *vet, int n);
void liberaMatriz(int **matriz, int n);

int main() {
    int **matriz = NULL, *valoresColuna = NULL;
    int nLin, nCol, opcao, somaTotal, colunaSelecionada;//, i;

    do {
        printf("1.Criar Matriz\n2.Inserir\n3.Somar\n4.Elementos da coluna\n5.Imprimir Matriz\n6.Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            
            case 1:
                printf("Informe o numero de colunas: ");
                scanf("%d", &nCol);

                printf("Informe o numero de linhas: ");
                scanf("%d", &nLin);

                matriz = criaMatriz(nLin, nCol);
                break;
            case 2: 
                leiaMatriz(matriz, nLin, nCol);
                break;

            case 3:
                somaTotal = somaMatriz(matriz, nCol, nLin);
                printf("Soma dos elementos da Matriz: %d\n", somaTotal);
                break;

            case 4:
                printf("Informe uma coluna: ");
                scanf("%d", &colunaSelecionada);
                valoresColuna = colunaMatriz(matriz, nLin, nCol, colunaSelecionada);
                imprimeVetor(valoresColuna, nLin);
                break;
            
            case 5:
                imprimeMatriz(matriz, nLin, nCol);
                break;
            
            case 6:
                break;

            default: 
                printf("Informe uma opcao valida\n");
        }
    } while (opcao != 6);

    free(valoresColuna);

    liberaMatriz(matriz, nLin);

    return 0;
}

int **criaMatriz(int nLin, int nCol) {
    int i,j, **matriz;
    
    matriz = (int**)malloc(nLin * sizeof(int*));

    if (!matriz) {
        printf("Erro ao alocar memoria\n");
        exit(0);
    }

    for(i = 0; i < nLin; i++) {
        matriz[i] = (int*)malloc(nCol * sizeof(int));

        if (!matriz[i]) {
            printf("Erro ao alocar memoria\n");
            exit(0); 
        }
    }

     for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

void leiaMatriz(int **matriz, int nLin, int nCol) {
    int i, j, valor;

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            printf("[%d, %d]: ", i, j);
            scanf("%d", &valor);

            matriz[i][j] = valor;
        }
    }
}

void imprimeMatriz(int **matriz, int nLin, int nCol) {
    int i, j;

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int somaMatriz(int **matriz, int nCol, int nLin) {
    int i, j, somador = 0;

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            somador += matriz[i][j];
        }
    }

    return somador;
}

int *colunaMatriz(int **matriz, int nLin, int nCol, int colunaSelecionada) {
    int i, j, *valoresColuna = NULL, tamanho = 1, index = 0;

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (j == colunaSelecionada) {
                if (!valoresColuna) {
                    valoresColuna = (int*)malloc(sizeof(int));
                    if (!valoresColuna) {
                        printf("Erro ao alocar memoria\n");
                        exit(1);
                    }
                } else {
                    tamanho++;
                    valoresColuna = (int*)realloc(valoresColuna, tamanho * sizeof(int));
                }
                valoresColuna[index++] = matriz[i][j];
            }
        }
    }
    
    return valoresColuna;
}

void imprimeVetor (int *valoresColuna, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", valoresColuna[i]);
    }

    printf("\n");

}

void liberaMatriz(int **matriz, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);

}
