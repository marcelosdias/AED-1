#include "funcoesAVL.h"

int main() {
    Apontador *p = NULL;
    Registro reg;

    int quantidade, i;

    srand(time(0));
    
    printf("Informe o numero de nodos: ");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        reg.chave = rand() % 100;

        insere(reg.chave, &p);
    }

    listar(p);

    if (EhArvoreArvl(p)) 
        printf("\nEh arvore AVL\n");
    else
        printf("\nNao eh arvore AVL\n");

    freeArvore(p);

    return 0;
}
