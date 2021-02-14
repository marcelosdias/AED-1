#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int matricula;
} Aluno;

typedef struct {
    Aluno *alunos;
    Aluno *topo;
    Aluno *base;
    int limite;
} Pilha;

void Reset(Pilha *pilha);
void PUSH(Pilha *pilha, Aluno *novoAluno);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);
bool Empty(Pilha *pilha);

int main() {
    Pilha *pilha = NULL;
    Aluno aluno;

    pilha = (Pilha*)malloc(sizeof(Pilha));

    Reset(pilha);

    aluno.matricula = 1;
    PUSH(pilha, &aluno);

    aluno.matricula = 2;
    PUSH(pilha, &aluno);

    aluno.matricula = 3;
    PUSH(pilha, &aluno);

    Listar(pilha);

    free(pilha);

    return 0;
}

void Reset(Pilha *pilha) {
    pilha->alunos = NULL;
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->limite = 0;
}   

bool Empty(Pilha *pilha) {
    return pilha->alunos == NULL; // Ou pilha->limite == 0
}

void PUSH(Pilha *pilha, Aluno *novoAluno) {
    if (Empty(pilha)) {
        pilha->limite++;
        pilha->alunos = (Aluno*)malloc(sizeof(Aluno*));

        if (Empty(pilha)) {
            printf("Erro ao Alocar Memoria\n");
            exit(1);
        }
    } else {
        pilha->limite++;
        pilha->alunos = (Aluno*)realloc(pilha->alunos, pilha->limite * sizeof(Aluno));
    }

    pilha->alunos[pilha->limite-1] = *novoAluno;
    pilha->topo = &pilha->alunos[pilha->limite-1];
    pilha->base = pilha->alunos;
}

void POP(Pilha *pilha, Aluno *aluno) {
    if (!Empty(pilha)) {
        *aluno = *pilha->topo;

        pilha->limite--;

        if (pilha->limite == 0) {
            free(pilha->alunos);
            Reset(pilha);
            return;
        }

        pilha->alunos = (Aluno*)realloc(pilha->alunos, pilha->limite * sizeof(Aluno));

        if (Empty(pilha)) {
            printf("Erro ao Alocar Memoria\n");
            exit(1);
        }

        pilha->topo = &pilha->alunos[pilha->limite-1];
        pilha->base = pilha->alunos;
    }
}

void Listar(Pilha *pilha) {
    Aluno aluno;

    while(!Empty(pilha)) {
        POP(pilha, &aluno);
        printf("%d\n", aluno.matricula);
    }
}