#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *nome;
  char *telefone;
  char *celular;
  char *endereco;
  char *aniversario;
} Contato;

int main(int argc, char const *argv[])
{
  Contato agenda[3];

  agenda[0].nome = "Mãe";
  agenda[0].telefone = "9999-9999";
  agenda[0].celular = "9999-9999";
  agenda[0].endereco = "Rua A";
  agenda[0].aniversario = "01/01/2000";

  agenda[1].nome = "José";
  agenda[1].telefone = "8888-8888";
  agenda[1].celular = "8888-8888";
  agenda[1].endereco = "Rua B";
  agenda[1].aniversario = "02/02/2000";

  agenda[2].nome = "Eu";
  agenda[2].telefone = "7777-7777";
  agenda[2].celular = "7777-7777";
  agenda[2].endereco = "Rua C";
  agenda[2].aniversario = "03/03/2000";

  printf("Digite o indice do contato: \n");

  for (int i = 0; i < 3; i++)
  {
    printf("%d - %s\n", i + 1, agenda[i].nome);
  }

  int indice;
  scanf("%d", &indice);

  if (indice < 1 || indice > 3)
  {
    printf("====================================================\n");
    printf("Indice invalido!\n");
    printf("====================================================\n");
    return 1;
  }

  indice = indice - 1;

  printf("Nome: %s\n", agenda[indice].nome);
  printf("Telefone: %s\n", agenda[indice].telefone);
  printf("Celular: %s\n", agenda[indice].celular);
  printf("Endereco: %s\n", agenda[indice].endereco);
  printf("Aniversario: %s\n", agenda[indice].aniversario);

  return 0;
}
