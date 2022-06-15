#include <stdio.h>
#include <stdlib.h>
#include "lista/double_linked_list.h"

int main()
{
  DLinkedList *lista = novaLista();

  inserir(&lista, novoNodo(novoContato()));
  inserir(&lista, novoNodo(novoContato()));
  inserir(&lista, novoNodo(novoContato()));
  imprimeFila(&lista);

  Contato *dado;
  remover(&lista, &dado, 1);

  imprimeContato(dado);
  imprimeFila(&lista);

  return 0;
}
