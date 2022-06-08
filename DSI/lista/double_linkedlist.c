#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct Nodo *next;
    struct Nodo *prev;
} Nodo;

typedef struct DLinkedList {
    int size;
    Nodo *head;
    Nodo *tail;
} DLinkedList;

Nodo *novoNodo(int dado) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->dado = dado;
    nodo->next = NULL;
    nodo->prev = NULL;
    return nodo;
}

DLinkedList *novaLista() {
    DLinkedList *lista = malloc(sizeof(DLinkedList));
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int vazia(DLinkedList **lista) {
    return (*lista)->size == 0;
}

int inserir(DLinkedList **lista, Nodo *nodo) {
    if(nodo!=NULL) {
        nodo->prev = (struct Nodo *) (*lista)->tail;
        if(vazia(lista)) (*lista)->head = nodo;
        else (*lista)->tail->next = (struct Nodo*) nodo;
        (*lista)->tail = nodo;
        (*lista)->size++;
        return 1;
    } else return 0;
}

int remover(DLinkedList **lista) {

}

int main() {
    // TODO
    return 0;
}
