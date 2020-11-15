#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[30];
    int idade;
    int numero;
} Dados;

struct nodo {
    Dados info;
    struct nodo *next;
    struct nodo *prev;
};

typedef struct nodo Nodo;

typedef struct {
    Nodo *pFirst;
    Nodo *pLast;
} Head;

void menu(void *pBuffer);
void menuOrdenar(Head *head, void *pBuffer);
void insere(Head *head);
void remover(Head *head, void *pBuffer);
void buscar(Head *head, void *pBuffer);
void listar(Head *head);
void ordenaIdadeCrescente(Head *head, void *pBuffer);
void ordenaIdadeDecrescente(Head *head, void *pBuffer);
void PUSH(Head *head, Head *head_aux, Nodo *current);
void POP(Head *head_aux, Nodo *current);
void listarFilaOrdenada(Head *head_aux);
void copiaDados(Nodo *newNodo, Nodo *nodo);
void leDados(Nodo *newNodo);
void leNome(void *pBuffer);
bool isEmpty(Head *head);
Nodo *criaNodo(void);
Head *criaHead(void);
void clear(Head *head);