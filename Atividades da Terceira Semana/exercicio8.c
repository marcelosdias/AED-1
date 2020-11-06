#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *separaPalavras(char *linha);
void imprime(char *listaPalavras);

int main() {
    char *linha, *listaPalavras = NULL;

    linha = (char*)malloc(80 * sizeof(char));

    if (!linha) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    printf("Informe uma frase: ");
    scanf("%[^\n]s", linha);

    listaPalavras = separaPalavras(linha);

    imprime(listaPalavras);

    free(listaPalavras);

    return 0;

}

char *separaPalavras(char *linha) {
    char nomeSelecionado[30], *listaPalavras = NULL;

    int i, j, tamanhoLinha, tamanhoNomeSelecionado, novoTamanho, tamanhoAtual = 0;

    tamanhoLinha = strlen(linha);

    for (i = 0; i < tamanhoLinha; i++) {
        j = 0;

        nomeSelecionado[j] = '\0';

        while (linha[i] != ' ' && linha[i] != ',' && linha[i] != '.' && linha[i] != ';' && linha[i] != '\0') 
            nomeSelecionado[j++] = linha[i++];

        if (nomeSelecionado[0] != '\0') {

            nomeSelecionado[j] = '\0';

            tamanhoNomeSelecionado = strlen(nomeSelecionado);

            if (!listaPalavras) {
                novoTamanho = tamanhoNomeSelecionado + 2;

                listaPalavras = (char*)malloc(novoTamanho * sizeof(char));

                if (!listaPalavras) {
                    printf("Erro ao alocar memoria\n");
                    exit(1);
                }

                strcpy(listaPalavras, nomeSelecionado);
                strcat(listaPalavras, ";");

            } else {
                novoTamanho = tamanhoAtual + tamanhoNomeSelecionado + 2;

                listaPalavras = (char*)realloc(listaPalavras, novoTamanho * sizeof(char));

                strcat(listaPalavras, nomeSelecionado);
                strcat(listaPalavras, ";");
            }
            tamanhoAtual = novoTamanho;
        }
    }

    if (!listaPalavras) {
        printf("Frase Invalida\n");
        exit(1);
    }

    linha = (char*)realloc(linha, tamanhoAtual * sizeof(char));

    memcpy(linha, listaPalavras, tamanhoAtual);

    free(listaPalavras);

    return linha;
}

void imprime(char *listaPalavras) {
    int i, tamanho = strlen(listaPalavras);

    for (i = 0; i < tamanho; i++) {
        if (listaPalavras[i] != ';') 
            printf("%c", listaPalavras[i]);
        else
            printf("\n");
    }
}