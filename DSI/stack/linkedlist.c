// This code represents a linked list that will be used as an
// implemention of a stack LIFO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    char telefone[20];
} Contato;

typedef struct {
    Contato *data;
    struct Nodo *nodo;
} Nodo;

typedef struct {
    Nodo *nodo;
} Pilha;

Pilha* pilha() {
    Pilha* head = (Pilha*) malloc(sizeof(Pilha));
    head->nodo = NULL;
    return head;
}

Nodo* nodo() {
    Nodo* head = (Nodo*) malloc(sizeof(Nodo));
    head->data = NULL;
    head->nodo = NULL;
    return head;
}

Contato* criarContato() {
    Contato* contato = (Contato*) malloc(sizeof(Contato));
    // printf("Insira o nome do contato: ");
    // scanf("%s", (*contato).nome);
    strcpy(contato->nome, "Thiago Farias");
    // printf("Insira o telefone do contato: ");
    // scanf("%s", (*contato).telefone);
    strcpy(contato->telefone, "5151515151");
    return contato;
}

void push(Pilha** head, Contato* contato) {
    Nodo *current = (*head)->nodo;
    while(current!=NULL) {
        current = (Nodo*) current->nodo;
    }
    current = nodo();
    current->data = contato;
}

void pop(Nodo* head);

void printEachNode(Pilha* head) {
    Nodo *current = head->nodo;
    while(current!=NULL) {
        printf("Contato - %s", current->data->nome);
    }
}

int main() { 
    Pilha* head = pilha();
    push(&head, criarContato());
    push(&head, criarContato());
    push(&head, criarContato());

    printEachNode(head);    
}
