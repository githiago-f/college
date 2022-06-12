#include <stdio.h>
#include <stdlib.h>
#include "contato.h"

Contato *novoContato()
{
  Contato *contato = (Contato *)malloc(sizeof(Contato));
  printf("insira um cpf: ");
  gets(contato->cpf);
  printf("insira um nome: ");
  gets(contato->nome);
  printf("insira um e-mail: ");
  gets(contato->email);
  return contato;
}

void imprimeContato(Contato *contato)
{
  printf("\nCPF: %s\n", contato->cpf);
  printf("Nome: %s\n", contato->nome);
  printf("E-mail: %s\n", contato->email);
}
