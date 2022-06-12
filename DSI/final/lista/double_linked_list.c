#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/cpf.h"

Nodo *novoNodo(Contato *dado)
{
  if (!dado)
  {
    printf("SO não pode alocar este espaço");
    return NULL;
  }
  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
  nodo->dado = dado;
  nodo->next = NULL;
  nodo->prev = NULL;
  return nodo;
}

DLinkedList *novaLista()
{
  DLinkedList *lista = malloc(sizeof(DLinkedList));
  lista->head = NULL;
  lista->tail = NULL;
  lista->size = 0;
  return lista;
}

int vazia(DLinkedList **lista)
{
  return (*lista)->size == 0;
}

int inserir(DLinkedList **lista, Nodo *nodo)
{
  if (nodo == NULL)
  {
    return 0;
  }
  if (vazia(lista))
  {
    (*lista)->head = nodo;
    (*lista)->tail = nodo;
    (*lista)->size++;
    return 1;
  }
  Nodo *current = (*lista)->head;
  while (current != NULL)
  {
    char *cpf1 = current->dado->cpf;
    char *cpf2 = nodo->dado->cpf;
    if (compararCpf(cpf1, cpf2) >= 0)
    {
      if (current->next == NULL)
      {
        current->next = nodo;
        nodo->prev = current;
        (*lista)->tail = nodo;
        break;
      }
      current = current->next;
      continue;
    }
    else
    {
      nodo->next = current;
      if (current->prev == NULL)
      {
        (*lista)->head = nodo;
      }
      current->prev = nodo;
      if (current->next == NULL)
      {
        (*lista)->tail = current;
      }
      break;
    }
  }
  (*lista)->size++;
  return 1;
}

int remover(DLinkedList **lista, Contato *data)
{
  Nodo *temp = (*lista)->head;
  if (vazia(lista))
    return 0;
  data = temp->dado;
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
  int numContato = 0;
  while (temp != NULL)
  {
    printf("Contato #%d\n", numContato);
    imprimeContato(temp->dado);
    temp = (Nodo *)temp->next;
    numContato++;
  }
  printf("\n\n");
}

Contato *consultar(DLinkedList **lista, int pos)
{
  if (vazia(lista))
  {
    printf("Lista vazia!");
    return NULL;
  }
  if ((tamanho(lista) - 1) < pos || pos < 0)
  {
    printf("Posição fora dos limites");
    return NULL;
  }
  Nodo *temp = (*lista)->head;
  int curPos = 0;
  while (temp != NULL)
  {
    if (curPos == pos)
    {
      return temp->dado;
    }
    temp = (Nodo *)temp->next;
    curPos++;
  }
}
