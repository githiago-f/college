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
  if (nodo != NULL)
  {
    nodo->prev = (struct Nodo *)(*lista)->tail;
    if (vazia(lista))
      (*lista)->head = nodo;
    else
      (*lista)->tail->next = (struct Nodo *)nodo;
    (*lista)->tail = nodo;
    (*lista)->size++;
    return 1;
  }
  else
    return 0;
}

int remover(DLinkedList **lista, int *d)
{
  Nodo *temp = (*lista)->head;
  if (vazia(lista))
    return 0;
  (*d) = temp->dado;
  if ((*lista)->head == (*lista)->tail)
    (*lista)->tail = NULL;
  (*lista)->head = (Nodo *)(*lista)->head->next;
  if ((*lista)->head != NULL)
    (*lista)->head->prev = NULL;
  (*lista)->size--;
  free(temp);
  return 1;
}

int tamanho(DLinkedList **lista)
{
  return (*lista)->size;
}

void imprimeFila(DLinkedList **lista)
{
  Nodo *temp = (*lista)->head;
  if (vazia(lista))
  {
    printf("Fila VAZIA.\n");
    return;
  }
  printf("\nElementos da fila: ");
  while (temp != NULL)
  {
    printf("%d ", temp->dado);
    temp = (Nodo *)temp->next;
  }
  printf("\n\n");
}

int main() {
  int i;
  int r, a, b;
  DLinkedList *fila = novaLista();

  imprimeFila(&fila);
  for (i = 0; i < 7; i++)
  {
    inserir(&fila, novoNodo(i));
    printf("inserindo %d. ", i);
    imprimeFila(&fila);
  }

  while (tamanho(&fila) > 1)
  {
    remover(&fila, &a);
    remover(&fila, &b);
    r = a + b;
    inserir(&fila, novoNodo(r));
    imprimeFila(&fila);
  }
  return 0;
}
