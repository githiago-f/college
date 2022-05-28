// This code represents a linked list that will be used as an
// implemention of a stack LIFO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char email[150];
    char fone[15];
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
    printf("Insira o nome do contato: ");
    scanf("%s", (*contato).nome);

    printf("Insira o telefone do contato: ");
    scanf("%s", (*contato).fone);

    printf("Insira o email do contato: ");
    scanf("%s", (*contato).email);
    return contato;
}

void push(Pilha **head, Contato *contato)
{
    // get top
    Nodo **top = &(*head)->nodo;
    Nodo *novoNodo = nodo();
    novoNodo->nodo = (struct Nodo *)*top;
    novoNodo->data = contato;
    (*head)->nodo = novoNodo;
}

int vazio(Pilha *head)
{
    if (head->nodo == NULL)
    {
        return 1;
    }
    return 0;
}

Nodo *pop(Pilha **head)
{
    if (vazio((*head)) == 1)
    {
        return NULL;
    }
    Nodo *top = (*head)->nodo;
    (*head)->nodo = top->nodo;
    top->nodo = NULL;
    return top;
}

void imprimeNodo(Nodo *node)
{
    Contato *contato = (*node).data;
    printf("Contato - %s", contato->nome);
    printf("| %s ", contato->fone);
    printf("| %s\n", contato->email);
}

void imprimeLista(Pilha **head)
{
    Nodo **current = &(*head)->nodo;
    while ((*current) != NULL)
    {
        imprimeNodo((*current));
        current = (Nodo **)&(*current)->nodo;
    }
}

int main() { 
    Pilha* head = pilha();
    push(&head, criarContato());
    push(&head, criarContato());
    push(&head, criarContato());

    Nodo *removed = pop(&head);

    printf("\n Item removido: \n");
    imprimeNodo(removed);

    printf("\n Itens atuais: \n");
    imprimeLista(&head);
}
