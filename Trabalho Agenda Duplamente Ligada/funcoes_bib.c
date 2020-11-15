/* Função para inserir um novo nodo na lista */
#include "funcoes_bib.h"

void insere(Head *head) {
    Nodo *newNodo = NULL;

    newNodo = criaNodo();

    leDados(newNodo);
    /* Testa se a lista está vazia, caso esteja vazia insere o primeiro elemento */
    if (head->pLast == NULL) {
        head->pFirst = newNodo;
    } else {
        /* Insere no final da lista */
        newNodo->prev = head->pLast;
        head->pLast->next = newNodo;
    }
    
    head->pLast = newNodo;
}

/* Função para buscar a pessoa pelo nome e deletar a mesma da lista */
void remover(Head *head, void *pBuffer) {
    Nodo *nodo;

    if (!isEmpty(head)) {

        leNome(pBuffer);

        for (nodo = head->pFirst; nodo != NULL; nodo = nodo->next) {
            if (strcmp(nodo->info.nome, ((char*)(pBuffer + 4 * sizeof(int)))) == 0) {
                /* Unico elemento da lista */
                if (nodo->prev == NULL) { 
                    if (nodo->next == NULL) {
                        head->pFirst = NULL;
                        head->pLast = NULL;
                        return;
                    } else {
                        /* Elimina o primeiro elemento da lista */
                        nodo->next->prev = NULL; 
                        head->pFirst = nodo->next;
                        free(nodo);
                        return;
                    }
                } else {
                    /* Elimina o ultimo elemento da lista */
                    if (nodo->next == NULL) { 
                        nodo->prev->next = NULL;
                        head->pLast = nodo->prev;
                        free(nodo);
                        return;

                    } else {
                        /* Elimina um elemento no meio da lista */
                        nodo->prev->next = nodo->next; 
                        nodo->next->prev = nodo->prev;
                        free(nodo);
                        return;
                    }
                }
            }
        }
    } else {
        printf("Lista Vazia\n");
        return;
    }

    printf("Nome nao encontrado\n");
}

/* Função para buscar e listar os dados da pessoa através do nome */
void buscar(Head *head, void *pBuffer) {
    Nodo *nodo;

    if (!isEmpty(head)) {
        leNome(pBuffer);

        /* Percorre toda lista */
        for (nodo = head->pFirst; nodo != NULL; nodo = nodo->next) {
            /* Compara para ver se o nome no nodo é igual a nome procurado, aṕos printar, sai da funcao */
            if (strcmp(nodo->info.nome, ((char*)(pBuffer + 4 * sizeof(int)))) == 0) {
                printf("Nome: %s; Idade: %d; Numero: %d\n", nodo->info.nome, nodo->info.idade, nodo->info.numero);
                return;
            }
        }
    } else {
        printf("Lista Vazia\n");
        return;
    }

    printf("Nome nao encontrado\n");
}

/* FUnção para listar todos os elementos da lista */
void listar(Head *head) {
    Nodo *nodo;

    /* Testa se a lista não está vazia e imprimi toda lista */
    if (!isEmpty(head)) 
        for (nodo = head->pFirst; nodo != NULL; nodo = nodo->next) 
            printf("Nome: %s; Idade: %d; Numero: %d\n", nodo->info.nome, nodo->info.idade, nodo->info.numero);
    else 
        printf("Lista Vazia\n");
    
}

/* Função para ordenar por idade de forme crescente. FIxa*/
void ordenaIdadeCrescente(Head *head, void *pBuffer) {
    Head *head_aux = NULL;
    Nodo *nodo, *current, *aux;

    if (isEmpty(head)) {
        printf("Lista Vazia\n");
        return;
    }

    head_aux = criaHead();

    *(int*)(pBuffer + sizeof(int)) = -1; // Utilizado para salvar o menor valor anterior

    /* Percorre todos os valores armazenados na lista */
    for (nodo = head->pFirst; nodo != NULL; nodo = nodo->next) {
        *(int*)(pBuffer) = 2147483647; // Utilizado para salvar o menor valor

        /* Percore a lista novamente comparando com o valor selecionado no for anterior */
        for (current = head->pFirst; current != NULL; current = current->next) {    

            /* Testa se o valor atual(current) é menor que o menor valor armazenado e maior que o valor salvo anteriomente */     
            if (current->info.idade < *(int*)(pBuffer) && current->info.idade > *(int*)(pBuffer + sizeof(int))) {
                *(int*)(pBuffer) = current->info.idade;
            }
        }
        *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer); // Salva o menor valor
        /* Percorre novamente toda a lista buscando todas aparições do menor valor armazenado para inserir todas juntas na fila */
        for (aux = head->pFirst; aux != NULL; aux = aux->next) {  
            if (*(int*)(pBuffer + sizeof(int)) == aux->info.idade) {
                PUSH(head, head_aux, aux);
            }
        }
    }
    listarFilaOrdenada(head_aux);
}

void ordenaIdadeDecrescente(Head *head, void *pBuffer) {
    Head *head_aux = NULL;
    Nodo *nodo, *current, *aux;

    if (isEmpty(head)) {
        printf("Lista Vazia\n");
        return;
    }

    head_aux = criaHead();

    *(int*)(pBuffer + sizeof(int)) = 2147483647; // // Utilizado para salvar o maior valor anterior

    /* Percorre todos os valores armazenados na lista */
    for (nodo = head->pFirst; nodo != NULL; nodo = nodo->next) {
        *(int*)(pBuffer) = -1; // // Utilizado para salvar o maior valor

        /* Percore a lista novamente comparando com o valor selecionado no for anterior */
        for (current = head->pFirst; current != NULL; current = current->next) {  

            /* Testa se o valor atual(current) é maior que o maior valor salvo e maior que o valor salvo anteriomente */
            if (current->info.idade > *(int*)(pBuffer) && current->info.idade < *(int*)(pBuffer + sizeof(int))) {
                *(int*)(pBuffer) = current->info.idade;
            }
        }
        *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer); // Salva o menor valor

        /* Percorre novamente toda a lista buscando todas aparições do menor valor armazenado para inserir todas juntas na fila */
        for (aux = head->pFirst; aux != NULL; aux = aux->next) {  
            if (*(int*)(pBuffer + sizeof(int)) == aux->info.idade) {
                PUSH(head, head_aux, aux);
            }
        }
    }
    listarFilaOrdenada(head_aux);
}

void PUSH(Head *head, Head *head_aux, Nodo *current) {
    Nodo *newNodo;

    newNodo = criaNodo();

    /* Copia todos os dados para o novo nodo */
    copiaDados(newNodo, current);

    /* Testa se a lista está vazia, caso esteja vazia insere o primeiro elemento */
    if (head_aux->pLast == NULL) {
        head_aux->pFirst = newNodo;
        
    } else {
        /* Insere no final da lista */
        newNodo->prev = head_aux->pLast;
        head_aux->pLast->next = newNodo;
    }

    head_aux->pLast = newNodo;
}

void copiaDados(Nodo *newNodo, Nodo *nodo) {
    strcpy(newNodo->info.nome, nodo->info.nome);
    newNodo->info.idade = nodo->info.idade;
    newNodo->info.numero = nodo->info.numero;
    newNodo->next = NULL;
    newNodo->prev = NULL;
}

void listarFilaOrdenada(Head *head_aux) {
    Nodo *nodo = head_aux->pFirst, *aux;

    while (nodo != NULL) {
        aux = nodo->next;
        printf("Nome: %s; Idade: %d; Numero: %d\n", nodo->info.nome, nodo->info.idade, nodo->info.numero);
        free(nodo);
        nodo = aux;
    }

    free(head_aux);
}

void menu(void *pBuffer) {
    printf("1.Inserir\n2.Remover\n3.Buscar\n4.Listar\n5.Ordenar\n6.Sair\nEscolha: ");
    scanf("%d", (int*)(pBuffer + (3 * sizeof(int))));
    getchar();
}

void menuOrdenar(Head *head, void *pBuffer) {
    printf("1.Ordenar por idade(Crescente)\n2.Ordenar por idade(Decrescente)\nEscolha: ");
    scanf("%d", (int*)(pBuffer + 4 * sizeof(int)));

    switch (*(int*)(pBuffer + 4 * sizeof(int))) {
        case 1: ordenaIdadeCrescente(head, pBuffer);
                break;
        case 2: ordenaIdadeDecrescente(head, pBuffer);
                break;
    }
}

void leDados(Nodo *newNodo) {
    printf("Informe o nome: ");
    scanf("%[^\n]s", newNodo->info.nome);

    printf("Informe a idade: ");
    scanf("%d", &newNodo->info.idade);
    getchar();

    printf("Informe o numero: ");
    scanf("%d", &newNodo->info.numero);

    getchar();

    newNodo->next = NULL;
    newNodo->prev = NULL;
}

void leNome(void *pBuffer) {
    printf("Informe o nome a ser removido: ");
    scanf("%[^\n]s", (char*)(pBuffer + 4 * sizeof(int)));
    getchar();
}

bool isEmpty(Head *head) {
    return head->pLast == NULL;
}

Head *criaHead(void) {
    Head *head;

    head = (Head*)malloc(sizeof(Head));

    if (!head) {
        printf("Erro ao Alocar");
        exit(1);
    }

    head->pFirst = NULL;
    head->pLast = NULL;

    return head;
}

Nodo *criaNodo(void) {
    Nodo *newNodo;

    newNodo = (Nodo*)malloc(sizeof(Nodo));

    if (!newNodo) {
        printf("Erro ao Alocar");
        exit(1);
    }

    return newNodo;
}

void clear(Head *head) {
    Nodo *nodo, *aux;

    nodo = head->pFirst;

    while (nodo != NULL) {
        aux = nodo->next;
        free(nodo);
        nodo = aux;
    }

    free(head);
}