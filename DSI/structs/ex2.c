#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *nome;
  char *telefoneEmergencia;
  char *contatoEmergencia;
  short idade;
} ContatoAluno;

ContatoAluno contatos[5];

void recebeDadosAluno(int indice)
{
  printf("====================================================\n");
  char nome[50], telefoneEmergencia[12], contatoEmergencia[12];
  short idade;

  printf("Digite o nome do aluno: ");
  scanf("%s", &nome);
  printf("Digite o telefone de emergencia: ");
  scanf("%s", &telefoneEmergencia);
  printf("Digite o contato de emergencia: ");
  scanf("%s", &contatoEmergencia);
  printf("Digite a idade do aluno: ");
  scanf("%hd", &idade);
  printf("====================================================\n");

  contatos[indice].nome = nome;
  contatos[indice].telefoneEmergencia = telefoneEmergencia;
  contatos[indice].contatoEmergencia = contatoEmergencia;
  contatos[indice].idade = idade;
}

void mostraInformacoesAluno(int indice)
{
  printf("====================================================\n");
  printf("Nome: %s\n", contatos[indice].nome);
  printf("Telefone de emergencia: %s\n", contatos[indice].telefoneEmergencia);
  printf("Contato de emergencia: %s\n", contatos[indice].contatoEmergencia);
  printf("Idade: %hd\n", contatos[indice].idade);
  printf("====================================================\n");
}

int main()
{
  for (int i = 0; i < 5; i++)
  {
    recebeDadosAluno(i);
  }

  printf("====================================================\n");
  printf("Digite o indice do aluno: \n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d - %s\n", i + 1, contatos[i].nome);
  }

  int indice = 1;
  scanf("%d", &indice);
  indice = indice - 1;

  if (indice < 1 || indice > 5)
  {
    printf("====================================================\n");
    printf("Indice invalido!\n");
    printf("====================================================\n");
    return 1;
  }

  mostraInformacoesAluno(indice);

  return 0;
}
