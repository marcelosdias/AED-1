#include "funcoesAVL.h"

int main() {
    Apontador *p = NULL;

    printf("|-----------CASO 1a-----------|\n");
    insere(20, &p);
    insere(4, &p);
    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 15\n");
    insere(15, &p);
    listar(p);
    
    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");

    freeArvore(p);
    p = NULL;

    printf("|-----------CASO 2a-----------|\n");
    insere(20, &p);
    insere(4, &p);
    insere(26, &p);
    insere(3, &p);
    insere(9, &p);

    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 15\n");
    insere(15, &p);
    listar(p);

    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");

    freeArvore(p);
    p = NULL;

    printf("|-----------CASO 3a-----------|\n");
    insere(20, &p);
    insere(4, &p);
    insere(26, &p);
    insere(3, &p);
    insere(9, &p);
    insere(21, &p);
    insere(30, &p);
    insere(2, &p);
    insere(7, &p);
    insere(11, &p);

    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 15\n");
    insere(15, &p);
    listar(p);

    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");

    freeArvore(p);
    p = NULL;

    printf("|-----------CASO 1b-----------|\n");
    insere(20, &p);
    insere(4, &p);
    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 8\n");
    insere(8, &p);
    listar(p);

    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");

    freeArvore(p);
    p = NULL;

    printf("|-----------CASO 2b-----------|\n");
    insere(20, &p);
    insere(4, &p);
    insere(26, &p);
    insere(3, &p);
    insere(9, &p);

    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 8\n");
    insere(8, &p);
    listar(p);

    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");

    freeArvore(p);
    p = NULL;

    printf("|-----------CASO 3b-----------|\n");
    insere(20, &p);
    insere(4, &p);
    insere(26, &p);
    insere(3, &p);
    insere(9, &p);
    insere(21, &p);
    insere(30, &p);
    insere(2, &p);
    insere(7, &p);
    insere(11, &p);

    printf("Arvore original\n");
    listar(p);

    printf("\nArvore apos inserir o valor 8\n");
    insere(8, &p);
    listar(p);

    if (EhArvoreArvl(p))
        printf("\nEh uma arvore AVL\n");
    else
        printf("\nNao eh uma arvore AVL\n");


    freeArvore(p);
    p = NULL;

    return 0;
}