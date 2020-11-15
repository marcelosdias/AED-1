#include "funcoes_bib.h"

int main() {
    Head *head = NULL;
    void *pBuffer = NULL;
    
    pBuffer = malloc(4 * sizeof(int) + 20 * sizeof(char));
    /* 0 - Armazena a idade
     * 1 - Armazena a idade anterior
     * 2 - Armazena o valor utilizado no switch do menu
     * 3 - Armazena o valor utilizado no switch da ordencação
     * 4 - Armazena um nome com tamanho máximo de 20 caracteres
     */

    head = criaHead();

    do {
        menu(pBuffer);

        switch (*(int*)(pBuffer + (3 * sizeof(int)))) {
            case 1: insere(head);
                    break;
            
            case 2: remover(head, pBuffer);    
                    break;

            case 3: buscar(head, pBuffer);
                    break;
            case 4: listar(head);
                    break;

            case 5: menuOrdenar(head, pBuffer);
                    break;
        }
    } while(*(int*)(pBuffer + (3 * sizeof(int))) != 6);

    clear(head);
    free(pBuffer);

    return 0;
}
