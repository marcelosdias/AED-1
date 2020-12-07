#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tipoChave;

typedef struct {
    tipoChave chave;
} Registro;

struct No {
    Registro reg;
    struct No *pDir, *pEsq;
};

typedef struct No Apontador;

int insere(int chave, Apontador **p);
void listar(Apontador *p);
int altura(Apontador *p);
int FB(Apontador *p);
void RSE(Apontador **p);
void RSD(Apontador **p);
int balanceamento(Apontador **p);
int balancaEsquerda(Apontador **p);
int balancaDireita(Apontador **p);
int EhArvoreArvl(Apontador *pRaiz);
void freeArvore(Apontador *node);
