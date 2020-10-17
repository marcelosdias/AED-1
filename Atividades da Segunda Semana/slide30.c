#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **criaMatriz(int nLin, int nCol);
void leiaMatriz(int **matriz, int nLin, int nCol);
void imprimeMatriz(int **matriz, int nLin, int nCol);
int somaMatriz(int **matriz, int nLin, int nCol);
int *colunaMatriz(int **matriz, int nLin, int nCol, int colunaSelecionada);
void imprimeVetor (int *vet, int n);
void liberaMatriz(int **matriz, int ncoluna);

int main() {
    int **matriz = NULL, *valoresColuna = NULL;
    int nLin, nCol, i, opcao, somaTotal, colunaSelecionada;


    do {
        printf("1.Criar Matriz\n2.Inserir\n5.Imprimir Matriz\nEscolha: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            
            case 1:
                printf("Informe o numero de colunas: ");
                scanf("%d", &nCol);

                printf("Informe o numero de linhas: ");
                scanf("%d", &nLin);

                matriz = criaMatriz(nCol, nLin);
                break;
            case 2: 
                leiaMatriz(matriz, nCol, nLin);
                break;

            case 3:
                somaTotal = somaMatriz(matriz, nCol, nLin);
                printf("Soma dos elementos da Matriz: %d\n", somaTotal);
                break;

            case 4:
                printf("Informe uma coluna: ");
                scanf("%d", &colunaSelecionada);
                valoresColuna = colunaMatriz(matriz, nLin, nCol, colunaSelecionada);
                break;
            
            case 5:
                imprimeMatriz(matriz, nLin, nCol);
                break;
            
            case 6:
                imprimeVetor(valoresColuna, nLin);
                break;

            case 7:
                break;

            default: 
                printf("Informe uma opcao valida\n");
        }
    } while (opcao != 7);
        
    return 0;
}

int **criaMatriz(int nLin, int nCol) {
    int i, **matriz;

    matriz = (int**)malloc(nLin * sizeof(int*));

    for(i = 0; i < nLin; i++) {
        matriz[i] = (int*)malloc(nCol * sizeof(int));
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

void imprimeMatriz(int **matriz, int nCol, int nLin) {
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