#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
} Dados;

struct nodo {
    Dados info;
    struct nodo *pNext;
};

typedef struct nodo Nodo;

typedef struct {
    Nodo *pFirst;
    Nodo *pLast;
} Head;

void PUSH(Head *head);
void POP(Head *head, Dados *item);
void Listar(Head *head);
Head *Reset(void);
Nodo *criaNodo(void);

int main() {
    Head *head = NULL;

    head = Reset();

    PUSH(head);
    PUSH(head);
    PUSH(head);
    PUSH(head);
    
    Listar(head);

    free(head);

    return 0;
}

void PUSH(Head *head) {
    Nodo *newNodo = NULL;

    newNodo = criaNodo();

    if (head->pLast != NULL) 
        head->pLast->pNext = newNodo;
    else
        head->pFirst = newNodo;

    head->pLast = newNodo;
}

void POP(Head *head, Dados *item) {
    Nodo *pNodo = NULL;

    if (head->pFirst == NULL) 
        printf("Lista Vazia\n");
    
    pNodo = head->pFirst;
    *item = head->pFirst->info;
    head->pFirst = head->pFirst->pNext;

    if (head->pFirst == NULL)
        head->pLast = NULL;

    free(pNodo);
}

void Listar(Head *head) {
    Dados item;

    printf("Listagem...\n");

    while (head->pFirst != NULL) {
        POP(head, &item);
        printf("%d\n", item.matricula);
    }
}

Head *Reset(void) {
    Head *head = NULL;

    head = (Head*)malloc(sizeof(Head));

    if (!head) {
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    head->pFirst = NULL;
    head->pLast = NULL;

    return head;
}

Nodo *criaNodo(void) {
    Nodo *newNodo = NULL;

    newNodo = (Nodo*)malloc(sizeof(Nodo));


    if (!newNodo) {
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    scanf("%d", &newNodo->info.matricula);

    newNodo->pNext = NULL;

    return newNodo;
}