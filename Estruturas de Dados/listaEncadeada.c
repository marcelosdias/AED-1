#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
} Dado;

struct Nodo {
    Dado alunos;
    struct Nodo *pNext;
};

typedef struct Nodo Nodo;

typedef struct {
    Nodo *pFirst;
} Head;


int PUSH(Head *head, unsigned int posicao);
int POP(Head *head, Nodo *pNodo, unsigned int posicao);
Head *Reset(void);
void Clear(Head *head);
void Listar(Head *head);
Nodo *criaNodo(void);

int main() {
    Head *head = NULL;

    head = Reset();
    
    PUSH(head, 0);
    PUSH(head, 1);
    PUSH(head, 2);
    PUSH(head, 0);

    Listar(head);

    Clear(head);

    return 0;

}

int PUSH(Head *head, unsigned int posicao) {
    Nodo *pAtual, *pAnterior, *newNodo = NULL;

    newNodo = criaNodo();

    if (head->pFirst == NULL && posicao != 0) return 0;

    else {
        if (head->pFirst == NULL && posicao == 0) {
            head->pFirst = newNodo;
            head->pFirst->pNext = NULL;
            return 1;
        } else {
            if (posicao == 0) {
                newNodo->pNext = head->pFirst;
                head->pFirst = newNodo;
                return 1;
            }
        }
    }

    pAtual = head->pFirst;

    for (int index = 0; index < posicao && pAtual != NULL; index++) {
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }

    newNodo->pNext = pAtual;
    pAnterior->pNext = newNodo;

    return 1;
}

int POP(Head *head, Nodo *pNodo, unsigned int posicao) {
    Nodo *pAtual, *pAnterior;

    if (head->pFirst == NULL) return 0;

    if (posicao == 0) {
        pNodo = head->pFirst;
        head->pFirst = head->pFirst->pNext;

        return 1;
    }

    pAtual = head->pFirst;

    for (int index = 0; index < posicao && pAtual != NULL; index++) {
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }

    if (!pAtual) return 0;

    pAnterior->pNext = pAtual->pNext;
    pNodo = pAtual;

    return 1;
}

void Listar(Head *head) {
    Nodo *p;

    printf("Listagem...\n");

    for (p = head->pFirst; p != NULL; p = p->pNext) 
        printf("%d\n", p->alunos.matricula);
}

Head *Reset(void) {
    Head *head = NULL;

    head = (Head*)malloc(sizeof(Head));

    if (!head) {
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    head->pFirst = NULL;

    return head;
}

void Clear(Head *head) {
    Nodo *p, *aux;

    p = head->pFirst;

    while(p != NULL) {
        aux = p;
        p = p->pNext;
        free(aux);
    }

    free(head);
}

Nodo *criaNodo(void) {
    Nodo *newNodo = NULL;

    newNodo = (Nodo*)malloc(sizeof(Nodo));

    if (!newNodo) {
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    scanf("%d", &newNodo->alunos.matricula);

    newNodo->pNext = NULL;

    return newNodo;
}