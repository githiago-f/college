#include "contato.h"

typedef struct
{
  Contato *dado;
  struct Nodo *next;
  struct Nodo *prev;
} Nodo;

typedef struct DLinkedList
{
  int size;
  Nodo *head;
  Nodo *tail;
} DLinkedList;

Nodo *novoNodo(Contato *dado);
DLinkedList *novaLista();
int vazia(DLinkedList **lista);
int inserir(DLinkedList **lista, Nodo *nodo);
int remover(DLinkedList **lista, Contato *data);
int tamanho(DLinkedList **lista);
void imprimeFila(DLinkedList **lista);
Contato *consultar(DLinkedList **lista, int pos);
