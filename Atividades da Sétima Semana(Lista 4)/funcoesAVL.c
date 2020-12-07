#include "funcoesAVL.h"

int insere(int chave, Apontador **p) {
    if (*p == NULL) {
        *p = (Apontador*)malloc(sizeof(Apontador));

        if (!p) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        (*p)->reg.chave = chave;

        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;

        return 1;
    } else if (chave < (*p)->reg.chave) {
        if (insere(chave, &(*p)->pEsq)) {
            if (balanceamento(p))
                return 0;
            else
                return 1;
        }
    } else if (chave > (*p)->reg.chave) {
        if (insere(chave, &(*p)->pDir)) {
            if (balanceamento(p))
                return 0;
            else
                return 1;
        }
    } else {
        return 0;
    }

    return 0; 
}

void listar(Apontador *p) {
    if (p != NULL) {
        printf("%d(", p->reg.chave);
        listar(p->pEsq);
        listar(p->pDir);
        printf(")");
    }
}

int altura(Apontador *p) {
    int iEsq, iDir;

    if (p == NULL) return 0;

    iEsq = altura(p->pEsq);
    iDir = altura(p->pDir);

    if (iEsq > iDir) 
        return iEsq + 1;
    else 
        return iDir + 1;
}

int FB(Apontador *p) {
    if (p == NULL) return 0;

    return altura(p->pEsq) - altura(p->pDir);
}

void RSE(Apontador **p) {
    Apontador *aux;

    aux = (*p)->pDir;
    (*p)->pDir = aux->pEsq;
    aux->pEsq = (*p);
    (*p) = aux;
}

void RSD(Apontador **p) {
    Apontador *aux;

    aux = (*p)->pEsq;
    (*p)->pEsq = aux->pDir;
    aux->pDir = (*p);
    (*p) = aux;
}

int balancaEsquerda(Apontador **p) {
    int fbe = FB((*p)->pEsq);

    if (fbe > 0) {
        RSD(p);

        return 1;
    } else if (fbe < 0) {
        RSE(&(*p)->pEsq);
        RSD(p);
        return 1;
    }
    return 0;
}

int balancaDireita(Apontador **p) {
    int fbd = FB((*p)->pDir);

    if (fbd < 0) {
        RSE(p);
        return 1;
    } else if (fbd > 0) {
        RSD(&(*p)->pDir);
        RSE(p);
        return 1;
    }
    return 0;
}

int balanceamento(Apontador **p) {
    int fb = FB(*p);

    if (fb > 1) 
        return balancaEsquerda(p);
    else if (fb < -1)
            return balancaDireita(p);
        else
            return 0;  
}

int EhArvoreArvl(Apontador *pRaiz) {
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

void freeArvore(Apontador *node) { 
    if (node == NULL) return; 
  
    freeArvore(node->pEsq); 
    freeArvore(node->pDir); 
    
    free(node); 
}  