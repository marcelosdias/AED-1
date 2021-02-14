#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX = 10;

typedef struct {
    int matricula;
} Aluno;

typedef struct {
    Aluno alunos[20];
    int topo;
    int base;
    int limite;
} Pilha;

void Reset(Pilha *pilha);
void PUSH(Pilha *pilha, Aluno novoALuno);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);
bool Empty(Pilha *pilha);
bool Full(Pilha *pilha);

int main() {
    Pilha *pilha = NULL;
    Aluno aluno;

    pilha = (Pilha*)malloc(sizeof(Pilha));

    if (!pilha) {
        printf("Erro ao Alocar memoria\n");
        exit(1);
    }
    
    Reset(pilha);

    aluno.matricula = 1;
    PUSH(pilha, aluno);

    aluno.matricula = 2;
    PUSH(pilha, aluno);

    aluno.matricula = 3;
    PUSH(pilha, aluno);

    Listar(pilha);

    free(pilha);
    
    return 0;
}

void Reset(Pilha *pilha) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

void PUSH(Pilha *pilha, Aluno novoALuno) {
    if (!Full(pilha)) 
        pilha->alunos[pilha->topo++] = novoALuno;
    else
        printf("Pilha esta cheia\n");
}

void POP(Pilha *pilha, Aluno *aluno) {
    if (Empty(pilha)) {
        printf("Pilha Esta Vazia\n");
        return;
    }

    pilha->topo--;
    *aluno = pilha->alunos[pilha->topo];
}

void Listar(Pilha *pilha) {
    Aluno aluno;
    
    while(!Empty(pilha)) {
        POP(pilha, &aluno);
        printf("%d\n", aluno.matricula);
    }
}

bool Empty(Pilha *pilha) {
    return pilha->topo == 0;
}

bool Full(Pilha *pilha) {
    return pilha->topo == MAX;
}