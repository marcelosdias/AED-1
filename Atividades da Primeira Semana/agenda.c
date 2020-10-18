#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *insere(void *pBuffer);
void *remover(void *pBuffer);
void buscar(void *pBuffer);
void listar(void *pBuffer);

int main() {
    void *pBuffer = NULL;

    pBuffer = malloc((4 * sizeof(int)) + (20 * sizeof(char))); //int quantPalavras, index, opcao, flag; char nome[20];
    // Os 20 primeiros endereços de char serão utlizados para ler o nome que deve ser removido

    if (!pBuffer) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    *(int*)pBuffer = 0;
    *(int*)(pBuffer + 3 * sizeof(int)) = 0;

    do {
        printf("1.Inserir\n2.Remover\n3.Buscar\n4.Listar\n5.Sair\nEscolha: ");
        scanf("%d", (int*)(pBuffer + (2 * sizeof(int)))); // Armazena no terceiro endereço de inteiros o valor utilizado para o switch
        getchar(); // Retira o '\n'

        switch (*(int*)(pBuffer + (2 * sizeof(int)))) {
            case 1:
                pBuffer = insere(pBuffer);
                break;

            case 2:
                pBuffer = remover(pBuffer);
                break;

            case 3:
                buscar(pBuffer);
                break;

            case 4:
                listar(pBuffer);
                break;
        }
    } while (*(int*)(pBuffer + (2 * sizeof(int))) != 5);

    free(pBuffer);
    
    return 0;
}

void *insere(void *pBuffer) {
    pBuffer = realloc(pBuffer, 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * ((*(int*)pBuffer) + 1))); // Adiciona +1 no primeiro endereço de inteiros, pois os 20 primeiros endereços de char serão utilizados para remover um nome


    printf("Informe o nome: ");
    scanf("%s", (char*)pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer)));
    
    printf("Informe o numero: ");
    scanf("%d", (int*)(pBuffer + 4 * sizeof(int) + 40 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * ((*(int*)pBuffer))))); // 40 * sizeof é utilizado para pular os 20 primeiros char + o nome que acabou de ser inserido.

    *(int*)(pBuffer) = *(int*)(pBuffer) + 1; // Incrementa a quantidade de palavras

    return pBuffer;
}

void *remover(void *pBuffer) {
    int c = sizeof(char), i = sizeof(int);
    printf("Informe um nome: ");
    scanf("%s", (char*)(pBuffer + 4 * sizeof(int)));

    for (*(int*)(pBuffer + sizeof(int)) = 0; *(int*)(pBuffer + sizeof(int)) < *(int*)(pBuffer); *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) { // Percorre todos os nomes armazenados, utlizando o primeiro (quantPalavras) e o segundo (i) endereço de inteiros
        if((strcmp((char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))), (char*)(pBuffer + 4 * sizeof(int)))) == 0) { // Compara todos os nomes armazenados com o nome armazenado nos 20 primeiros endereços de char
            strcpy((char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))), (char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer - 1)))); //Se o nome deve ser removido, copia o último nome armazenado para esse endereço
            
            *(int*)(pBuffer + 4 * sizeof(int) + 40 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))) = *(int*)(pBuffer + 4 * sizeof(int) + 40 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer - 1)));
            
            *(int*)pBuffer = *(int*)pBuffer - 1; //Decrementa o contador de palavras

            pBuffer = realloc(pBuffer, 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * ((*(int*)pBuffer)))); // Redimensiona o ponteiro, retirando os espaços ocupados pelo nome retirado
            
            *(int*)(pBuffer + 3 * sizeof(int)) = 1;
        }
    }

    if (*(int*)(pBuffer + 3 * sizeof(int)) == 0) {
        printf("Nome nao encontrado\n");
    } else {
        *(int*)(pBuffer + 3 * sizeof(int)) = 0;
    }

    return pBuffer;
}

void buscar(void *pBuffer) {
    printf("Informe um nome: ");
    scanf("%s", (char*)(pBuffer + 4 * sizeof(int)));

    for (*(int*)(pBuffer + sizeof(int)) = 0; *(int*)(pBuffer + sizeof(int)) < *(int*)(pBuffer); *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) { // Percorre todos os nomes armazenados, utlizando o primeiro (quantPalavras) e o segundo (i) endereço de inteiros
        if((strcmp((char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))), (char*)(pBuffer + 4 * sizeof(int)))) == 0) { // Compara todos os nomes armazenados com o nome armazenado nos 20 primeiros endereços de char
            printf("Nome: %s; ", (char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))));
            printf("numero: %d\n", *(int*)(pBuffer + 4 * sizeof(int) + 40 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))))));
            *(int*)(pBuffer + 3 * sizeof(int)) = 1;
        }
    }

    if (*(int*)(pBuffer + 3 * sizeof(int)) == 0) {
        printf("Nome nao encontrado\n");
    } else {
        *(int*)(pBuffer + 3 * sizeof(int)) = 0;
    }
}

void listar(void *pBuffer) {
    if (*(int*)pBuffer > 0) {
        for (*(int*)(pBuffer + sizeof(int)) = 0; *(int*)(pBuffer + sizeof(int)) < *(int*)(pBuffer); *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) { // Percorre todos os nomes armazenados, utlizando o primeiro (quantPalavras) e o segundo (i) endereóc de inteiros
            printf("Nome: %s; ", (char*)(pBuffer + 4 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int)))))); // Lista todos os nomes
            printf("Numero: %d\n", *(int*)(pBuffer + 4 * sizeof(int) + 40 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int)))))); // Lista todos os nomes
        }
    } else {
        printf("Lista Vazia\n");
    }
}