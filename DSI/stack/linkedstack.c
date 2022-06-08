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
        printf("A pilha atual está vazia.");
        return NULL;
    }
    Nodo *top = (*head)->nodo;
    (*head)->nodo = (Nodo *)top->nodo;
    top->nodo = NULL;
    return top;
}

void imprimeNodo(Nodo *node)
{
    if (node == NULL)
    {
        printf("Nenhum contato");
        return;
    }
    Contato *contato = (*node).data;
    printf("Contato - %s", contato->nome);
    printf("| %s ", contato->fone);
    printf("| %s\n", contato->email);
}

void imprimeLista(Pilha **head)
{
    if ((*head) == NULL)
    {
        printf("Pilha vazia");
        return;
    }
    Nodo **current = &(*head)->nodo;
    while ((*current) != NULL)
    {
        imprimeNodo((*current));
        current = (Nodo **)&(*current)->nodo;
    }
}

int main()
{
    // 1 - inserir contatos de 1 a 3
    // 2 - remover um Contato  e imprimir em tela os dados
    // 3 - remover um Contato  e imprimir em tela os dados
    // 4 -  empilhar um novo contato
    // 5 - remover um Contato  e imprimir em tela os dados
    // 6 - remover um Contato  e imprimir em tela os dados
    // 7 – tentar remover contato (deve dar erro)

    Pilha* head = pilha();
    // task 1
    push(&head, criarContato()); // 1
    push(&head, criarContato()); // 2
    push(&head, criarContato()); // 3

    // task 2
    Nodo *removed = pop(&head);
    printf("\n Item removido: \n");
    imprimeNodo(removed);

    // task 3
    removed = pop(&head);
    printf("\n Item removido: \n");
    imprimeNodo(removed);

    // task 4
    push(&head, criarContato());

    // task 5
    removed = pop(&head);
    printf("\n Item removido: \n");
    imprimeNodo(removed);

    // task 6
    removed = pop(&head);
    printf("\n Item removido: \n");
    imprimeNodo(removed);

    // task 7
    removed = pop(&head);
    printf("\n Item removido: \n");
    imprimeNodo(removed);

    // lista final
    printf("\n Itens atuais: \n");
    imprimeLista(&head);
}
