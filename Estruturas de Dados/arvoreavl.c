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

int insere(No **ppRaiz, Registro newRegistro);
int FB(No *pRaiz);
int altura(No *pRaiz);
void RSE(No **pNodo);
void RSD(No **pNodo);
int balanceamento(No **ppRaiz);
int balancaEsquerda(No **ppRaiz);
int balancaDireita(No **ppRaiz);
void leRegistro(Registro *registro);
void leChave(Registro *registro);
No *criaNo(void);
void preOrdem(No *pNodo);
void freeArvore(No *node);
int EhArvoreArvl(No *pRaiz);

int main() {
    No *pRaiz = NULL, *pAux = NULL;
    Registro registro;

    int opcao;

    do {
        printf("1.Inserir\n2.Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao != 2) {
            leRegistro(&registro);
            insere(&pRaiz, registro);
        }
    } while (opcao != 2);

    preOrdem(pRaiz);
    printf("\n");

    if(EhArvoreArvl(pRaiz))
        printf("Eh Arvore AVL\n");
    else
        printf("Nao eh Arvore AVL\n");

    freeArvore(pRaiz);

    return 0;
}

int insere(No **ppRaiz, Registro newRegistro) {
    if (*ppRaiz == NULL) {
        *ppRaiz = criaNo();
        (*ppRaiz)->registro = newRegistro;
        return 1;
    } else if (newRegistro.chave < (*ppRaiz)->registro.chave) {
        if (insere(&(*ppRaiz)->pEsq, newRegistro)) {
            if (balanceamento(ppRaiz)){
                return 0;
            }
            else
                return 1;
        }
    } else if (newRegistro.chave > (*ppRaiz)->registro.chave) {
        if (insere(&(*ppRaiz)->pDir, newRegistro)) {
            if (balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
    } else 
        return 0;
}

int FB(No *pRaiz) {
    if (pRaiz == NULL)
        return 0;

    return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

int altura(No *pRaiz) {
    int iEsq, iDir;

    if (pRaiz == NULL)
        return 0;

    iEsq = altura(pRaiz->pEsq);
    iDir = altura(pRaiz->pDir);

    if (iEsq > iDir)
        return iEsq + 1;
    else
        return iDir + 1;
}

/* Rotação Simples para Esquerda */
void RSE(No **pNodo) {
    No *pAux = NULL;

    pAux = (*pNodo)->pDir;
    (*pNodo)->pDir = pAux->pEsq;
    pAux->pEsq = (*pNodo);
    (*pNodo) = pAux;
}

/* Rotação Simples para Direira */
void RSD(No **pNodo) {
    No *pAux = NULL;

    pAux = (*pNodo)->pEsq;
    (*pNodo)->pEsq = pAux->pDir;
    pAux->pDir = (*pNodo);
    (*pNodo) = pAux;
}

int balanceamento(No **ppRaiz) {
    int fb = FB(*ppRaiz);

    if (fb > 1)
        return balancaEsquerda(ppRaiz);
    else if (fb < -1)
            return balancaDireita(ppRaiz);
        else
            return 0;
}

int balancaEsquerda(No **ppRaiz) {
    int fbe = FB((*ppRaiz)->pEsq);

    if (fbe > 0) {
        RSD(ppRaiz);

        return 1;
    } else if (fbe < 0) {
        RSE(&(*ppRaiz)->pEsq);
        RSD(ppRaiz);

        return 1;
    }
    return 0;
}

int balancaDireita(No **ppRaiz) {
    int fbd = FB((*ppRaiz)->pDir);

    if (fbd < 0) {
        RSE(ppRaiz);

        return 1;

    } else if (fbd > 0) {
        RSD(&(*ppRaiz)->pDir);
        RSE(ppRaiz);
        
        return 1;
    }

    return 0;
}

void preOrdem(No *pNodo) {
    if (pNodo != NULL) {
        printf("%d(", pNodo->registro.chave);
        preOrdem(pNodo->pEsq);
        preOrdem(pNodo->pDir);
        printf(")");
    }
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

int EhArvoreArvl(No *pRaiz) {
    int fb;
    if (pRaiz == NULL) return 1;

    if (!EhArvoreArvl(pRaiz->pEsq))
        return 0;

    if (!EhArvoreArvl(pRaiz->pDir))
        return 0;

    fb = FB (pRaiz);
    
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

void freeArvore(No *node) { 
    if (node == NULL) return; 
  
    freeArvore(node->pEsq); 
    freeArvore(node->pDir); 
    
    free(node); 
}  
