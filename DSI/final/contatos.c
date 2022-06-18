#include <stdio.h>
#include <stdlib.h>
#include "lista/double_linked_list.h"

int main()
{
  DLinkedList *lista = novaLista();

  printf("Insira contatos:\n");
  inserir(&lista, novoNodo(novoContato()));
  inserir(&lista, novoNodo(novoContato()));
  inserir(&lista, novoNodo(novoContato()));

  printf("Contatos:\n");
  imprimeFila(&lista);

  printf("Removendo da posição #1:\n");
  Contato *dado;
  remover(&lista, &dado, 1);

  printf("Contato removido da posição #1:\n");
  imprimeContato(dado);

  imprimeFila(&lista);

  return 0;
}
