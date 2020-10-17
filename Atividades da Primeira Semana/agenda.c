#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *insere(void *pBuffer);
void *remover(void *pBuffer);
void listar(void *pBuffer);

int main() {
    void *pBuffer;

    pBuffer = malloc((3 * sizeof(int)) + (20 * sizeof(char))); //int quantPalavras, i, opcao; char nome[20];
    // Os 20 primeiros endereços de char serão utlizados para ler o nome que deve ser removido

    *(int*)pBuffer = 0;

    do {
        printf("1.Inserir\n2.Remover\n3.Listar\n4.Sair\nEscolha: ");
        scanf("%d", (int*)(pBuffer + (3 * sizeof(int)))); // Armazena no terceiro endereço de inteiros o valor utilizado para o switch
        getchar(); // Retira o '\n'

        switch (*(int*)(pBuffer + (3 * sizeof(int)))) {
            case 1:
                pBuffer = insere(pBuffer);
                break;

            case 2:
                pBuffer = remover(pBuffer);
                break;

            case 3:
                listar(pBuffer);
                break;
        }
    } while (*(int*)(pBuffer + (3 * sizeof(int))) != 4);

    free(pBuffer);
    
    return 0;
}

void *insere(void *pBuffer) {
    pBuffer = realloc(pBuffer, 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * ((*(int*)pBuffer) + 1))); // Adiciona +1 no primeiro endereço de inteiros, pois os 20 primeiros endereços de char serão utilizados para remover um nome

    printf("Informe o nome: ");
    scanf("%s", (char*)pBuffer + 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * (*(int*)pBuffer)));
        
    *(int*)(pBuffer) = *(int*)(pBuffer) + 1; // Incrementa a quantidade de palavras

    return pBuffer;
}

void *remover(void *pBuffer) {
    printf("Informe um nome: ");
    scanf("%s", (char*)(pBuffer + 3 * sizeof(int)));

    for (*(int*)(pBuffer + sizeof(int)) = 0; *(int*)(pBuffer + sizeof(int)) < *(int*)(pBuffer); *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) { // Percorre todos os nomes armazenados, utlizando o primeiro (quantPalavras) e o segundo (i) endereço de inteiros
        if((strcmp((char*)(pBuffer + 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * (*(int*)(pBuffer + sizeof(int))))), (char*)(pBuffer + 3 * sizeof(int)))) == 0) { // Compara todos os nomes armazenados com o nome armazenado nos 20 primeiros endereços de char
            strcpy((char*)(pBuffer + 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * (*(int*)(pBuffer + sizeof(int))))), (char*)(pBuffer + 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * (*(int*)pBuffer - 1)))); //Se o nome deve ser removido, copia o último nome armazenado para esse endereço
            
            *(int*)pBuffer = *(int*)pBuffer - 1; //Decrementa o contador de palavras

            pBuffer = realloc(pBuffer, 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * ((*(int*)pBuffer)))); // Redimensiona o ponteiro, retirando os espaços ocupados pelo nome retirado
        }
    }

    return pBuffer;
}

void listar(void *pBuffer) {
    for (*(int*)(pBuffer + sizeof(int)) = 0; *(int*)(pBuffer + sizeof(int)) < *(int*)(pBuffer); *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) { // Percorre todos os nomes armazenados, utlizando o primeiro (quantPalavras) e o segundo (i) endereóc de inteiros
        printf("%s\n", (char*)(pBuffer + 3 * sizeof(int) + 20 * sizeof(char) + ((20 * sizeof(char)) * (*(int*)(pBuffer + sizeof(int)))))); // Lista todos os nomes
    }
}