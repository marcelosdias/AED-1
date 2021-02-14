#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    int num;
} Registro;

struct No {
    Registro registro;
    struct No *pEsq;
    struct No *pDir;
};

typedef struct No No;

void insere(No **pNodo, Registro newRegistro);
void remover(No **pNodo, Registro registro);
void antecessor(No *pNodo, No **pEsq);
void menuMostrar(No *pRaiz);
void preOrdem(No *pNodo);
void central(No *pNodo);
void posOrdem(No *pNodo);
No *buscar(No *pNodo, Registro *registro);
void leRegistro(Registro *registro);
void leChave(Registro *registro);
No *criaNo(void);

int main() {
    No *pRaiz = NULL, *pAux = NULL;
    Registro registro;

    int opcao;

    do {
        printf("1.Inserir\n2.Remover\n3.Buscar\n4.Listar\n5.Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: leRegistro(&registro);
                    insere(&pRaiz, registro);
                    break;

            case 2: leChave(&registro);
                    remover(&pRaiz, registro);
                    break;

            case 3: leChave(&registro);
                    pAux = buscar(pRaiz, &registro);
                    if (pAux) 
                        printf("Chave: %d; Numero: %d\n", pAux->registro.chave, pAux->registro.num);
                    else
                        printf("Registro nao encontrado\n");
                    break;

            case 4: menuMostrar(pRaiz);
                    break;
        }
    } while (opcao != 5);

    return 0;
}

void insere(No **pNodo, Registro newRegistro) {
    if (*pNodo == NULL) {
        *pNodo = criaNo();
        (*pNodo)->registro = newRegistro;
        return;
    } else if (newRegistro.chave < (*pNodo)->registro.chave) {
        insere(&(*pNodo)->pEsq, newRegistro);
        return;
    } else if (newRegistro.chave > (*pNodo)->registro.chave) {
        insere(&(*pNodo)->pDir, newRegistro);
        return;
    } else printf("Erro: Registro ja existe na arvore\n");
}

void remover(No **pNodo, Registro registro) {
    No *pAux = NULL;

    if (*pNodo == NULL) {
        printf("Erro: Registro nao encontrado");
        return;
    }

    if (registro.chave < (*pNodo)->registro.chave) {
        remover(&(*pNodo)->pEsq, registro);
        return;
    }

    if (registro.chave > (*pNodo)->registro.chave) {
        remover(&(*pNodo)->pDir, registro);
        return;
    } 

    if ((*pNodo)->pDir == NULL) {
        pAux = *pNodo;
        *pNodo = (*pNodo)->pEsq;
        free(pAux);
        return;
    }

    if ((*pNodo)->pEsq != NULL) {
        antecessor(*pNodo, &(*pNodo)->pEsq);
        return;
    }

    pAux = *pNodo;
    *pNodo = (*pNodo)->pDir;
    free(pAux);
} 

void antecessor(No *pNodo, No **pEsq) {
    No *pAux;

    if ((*pEsq)->pDir != NULL) {
        antecessor(pNodo, &(*pNodo).pDir);
        return;
    }

    pNodo->registro = (*pEsq)->registro;
    pAux = *pEsq;
    *pEsq = (*pEsq)->pEsq;
    free(pAux);
}

void menuMostrar(No *pRaiz) {
    int opcao;

    printf("1.Pre-Ordem\n2.Central\n3.Pos-Ordem\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: preOrdem(pRaiz);   
                printf("\n");
                break;
            
        case 2: central(pRaiz);
                printf("\n");
                break;
        case 3: posOrdem(pRaiz);
                printf("\n");
                break;
    }
}

void preOrdem(No *pNodo) {
    if (pNodo != NULL) {
        printf("%d ", pNodo->registro.chave);
        preOrdem(pNodo->pEsq);
        preOrdem(pNodo->pDir);
    }
}

void central(No *pNodo) {
    if (pNodo != NULL) {
        central(pNodo->pEsq);
        printf("%d ", pNodo->registro.chave);
        central(pNodo->pDir);
    }
}

void posOrdem(No *pNodo) {
    if (pNodo != NULL) {
        posOrdem(pNodo->pEsq);
        posOrdem(pNodo->pDir);
        printf("%d ", pNodo->registro.chave);
    }
}

No *buscar(No *pNodo, Registro *registro) {
    if (pNodo == NULL) return NULL;
    if (pNodo->registro.chave == registro->chave) return pNodo;

    if (pNodo->registro.chave > registro->chave) 
        return (buscar(pNodo->pEsq, registro));
    else 
        return (buscar(pNodo->pDir, registro));
}


No *criaNo(void) {
    No *newNodo = NULL;

    newNodo = (No*)malloc(sizeof(No));

    if (!newNodo) {
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    newNodo->pDir = NULL;
    newNodo->pEsq = NULL;

    return newNodo;
}

void leRegistro(Registro *registro) {
    leChave(registro);

    printf("Informe um numero: ");
    scanf("%d", &registro->num);
}

void leChave(Registro *registro) {
    printf("Informe a chave: ");
    scanf("%d", &registro->chave);
}