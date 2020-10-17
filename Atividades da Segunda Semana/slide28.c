#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

int main () {
    Pessoa *p;

    int i, index = 0, tamanho = 1, opcao;

    p = (Pessoa*)malloc(sizeof(Pessoa));

    if (!p) {
        printf("Erro a alocar memoria\n");
        exit(1);
    } 
    
    do {
        printf("Informe o nome: ");
        scanf("%[^\n]s", p[index].nome);

        printf("Informe a idade: ");
        scanf("%d", &p[index].idade);

        printf("Informe a altura: ");
        scanf("%d", &p[index].altura);

        printf("Adicionar outro registro (1.Sim 2.Nao): ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            p = (Pessoa*)realloc(p, ++tamanho * sizeof(Pessoa));
            index++;
        }
    } while (opcao != 2);

    for (i = 0; i <= index; i++) {
        printf("Nome: %s; Idade: %d; Altura: %d\n", p[i].nome, p[i].idade, p[i].altura);
    }

    free(p);

    return 0;
}
