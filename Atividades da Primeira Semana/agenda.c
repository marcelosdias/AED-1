#include <stdio.h>
#include <stdlib.h>

void *insere(void *pBuffer);
void listar(void *pBuffer);

int main() {
    void *pBuffer;

    pBuffer = malloc(3 * sizeof(int) + 10 * sizeof(char)); // aloca 2 espaços para interos(quantPalavras, variavel para uso no for) e 10 para caracteres
    // int quantPalavras; int i; int opcao; char nome[10];

    *(int*)pBuffer = 0; // Inicializa o contador de palavras em zero;
    for (;;) {
        printf("1.Insere\n2.Remover\n3.Listar\n4.Listar\nEscolha: ");
        scanf("%d", (int*)pBuffer + 2 * sizeof(int));
        getchar();
        switch (*((int*)pBuffer + 2 * sizeof(int))) {
            case 1:
                pBuffer = insere(pBuffer);
                break;

            case 3:
                printf("%s\n", (char*)pBuffer + 3*sizeof(int) + 10*sizeof(char));
                listar(pBuffer);    
                break;
        }
    }

    return 0;
}

void *insere(void *pBuffer) {
    pBuffer = realloc(pBuffer, (3 * sizeof(int)) + (10 * sizeof(char)) + (((3 * sizeof(int)) + (10 * sizeof(char))) * (*(int*)pBuffer)));

    printf("Informe um nome: ");
    scanf("%s", (char*)pBuffer + (3 * sizeof(int)) + (10 * sizeof(char)) + ((3 * sizeof(int)) + (10 * sizeof(char)) * (*(int*)pBuffer)));

    printf("%s\n", (char*)pBuffer + 3 * sizeof(int) + 10 * sizeof(char));

    *(int*)pBuffer = *(int*)pBuffer + 1;

    printf("%d\n", *(int*)pBuffer);

    return pBuffer;
}

void listar(void *pBuffer) {
    for (*((int*)pBuffer + sizeof(int)) = 0; *((int*)pBuffer + sizeof(int)) < *(int*)pBuffer; *((int*)pBuffer + sizeof(int)) = *((int*)pBuffer + sizeof(int)) + 1) {
        printf("%s\n", (char*)pBuffer + (3 * sizeof(int)) + (10 * sizeof(char)) + ((3 * sizeof(int)) + 10 * sizeof(char)) * (*(int*)pBuffer + sizeof(int)));
    }
}