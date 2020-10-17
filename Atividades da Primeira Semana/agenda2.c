#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *insere(char* listaNomes);
char *remover(char *listaNomes);
void imprimir(char *listaNomes);


int main() {
    char *listaNomes = NULL;
    int opcao;

     do {
        printf("1.Inserir\n2.Deletar\n3.Listar\n4.Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
       switch (opcao) {
           case 1: 
                listaNomes = insere(listaNomes);
                break;

            case 2:
                listaNomes = remover(listaNomes);
                break;
                
            case 3:
                imprimir(listaNomes);
                break;        
        }
    } while (opcao !=  4);

    free(listaNomes);

    return 0;
}

char *insere(char* listaNomes) {
    int novoTamanho, tamanhoListaNomes = 0, tamanho;

    char *nome;

    nome = (char*)malloc(20 * sizeof(char));

    if (!nome) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    printf("Informe um nome: ");
    scanf("%[^\n]s", nome);

    strcat(nome, ",");

    tamanho = strlen(nome);

    if (!listaNomes) {
        novoTamanho = tamanho + 1;
        listaNomes = (char*)malloc(novoTamanho * sizeof(char));
        if (!listaNomes) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        strcpy(listaNomes, nome);
    } else {
        tamanhoListaNomes = strlen(listaNomes); 
        novoTamanho = tamanhoListaNomes + tamanho + 1;

        listaNomes = (char*)realloc(listaNomes, novoTamanho * sizeof(char));

        strcat(listaNomes, nome);
    }

    free(nome);

    return listaNomes;
}

char *remover(char *listaNomes) {
    int indiceListaNomes, indiceNomeSelecionado, tamanhoListaNomes, tamanhoListaNomesAux = 0, tamanhoNomeSelecionado, novoTamanho, quantidadeNomeRetirado = 0;
    char nomeRetirado[20], nomeSelecionado[20], *listaNomesAux = NULL;

    if (!listaNomes) {
        printf("Registre um nome primeiro\n");
        return NULL;
    } else {    
        printf("Informe qual nome deve ser retirado: ");
        scanf("%[^\n]s", nomeRetirado);

       tamanhoListaNomes = strlen(listaNomes);

        for (indiceListaNomes = 0; indiceListaNomes < tamanhoListaNomes; indiceListaNomes++) {
            indiceNomeSelecionado = 0;

            while (listaNomes[indiceListaNomes] != ',') 
                nomeSelecionado[indiceNomeSelecionado++] = listaNomes[indiceListaNomes++];
        
            nomeSelecionado[indiceNomeSelecionado] = '\0';

            tamanhoNomeSelecionado = strlen(nomeSelecionado);

            if (strcmp(nomeSelecionado, nomeRetirado) != 0) {
                if (!listaNomesAux) {
                    novoTamanho = tamanhoNomeSelecionado + 2; //Acrescentando ',' e o fim da string
                    listaNomesAux = (char*)malloc(novoTamanho * sizeof(char));
                    if (!listaNomesAux) {
                        printf("Erro ao alocar memoria\n");
                        exit(1);
                    }
                    
                    strcpy (listaNomesAux, nomeSelecionado);
                    strcat (listaNomesAux, ",");

                } else {
                    novoTamanho = tamanhoListaNomesAux + tamanhoNomeSelecionado + 2; //Acrescentando ',' e o fim da string
                    listaNomesAux = (char*)realloc(listaNomesAux, novoTamanho * sizeof(char));
                    strcat (listaNomesAux, nomeSelecionado);
                    strcat (listaNomesAux, ",");
                }
                
                tamanhoListaNomesAux = novoTamanho;

            } else {
                quantidadeNomeRetirado++;
            }
        }

        if (quantidadeNomeRetirado == 0) {
            printf("Nome nao encontrado\n");

            free(listaNomesAux);

            return listaNomes;
        } else {
            listaNomes = (char*)realloc(listaNomes, quantidadeNomeRetirado * tamanhoListaNomesAux * sizeof(char));

            if (!listaNomesAux) {
                free(listaNomesAux);

                return NULL;

            } else {
                strcpy(listaNomes, listaNomesAux);
                free(listaNomesAux);
            }
        }
    }
    return listaNomes;
}

void imprimir(char *listaNomes) {
    if (listaNomes) {
        while (*listaNomes) {
            if (*listaNomes != ',') {
                printf("%c", *listaNomes++);
            } else {
                listaNomes++;
                printf("\n");
            }
        }
    } else {
        printf("Lista Esta Vazia\n");
    }
}
