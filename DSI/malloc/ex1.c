#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[40];
  char telefone[15];
} Contato;

int main() {
  Contato *contato;
  contato = (Contato*) malloc(sizeof(Contato));
  if(!contato) {
    printf("Contato não foi alocado");
    return 1;
  }
  scanf("%s", (*contato).nome);
  strcpy((*contato).telefone, "1234567");
  printf("Nome = %s\nTelefone= %s\n", (*contato).nome, (*contato).telefone);
  free(contato);

  contato = NULL;

  printf("Nome = %s\nTelefone= %s\n", (*contato).nome, (*contato).telefone);
  return 0;
}