#include <stdio.h>
#include <stdlib.h>

const short NUM_ALUNOS = 5;

typedef struct
{
  char *nome;
  char *telefoneEmergencia;
  char *contatoEmergencia;
  short idade;
} ContatoAluno;

void lerInfos(ContatoAluno *aluno)
{
  printf("Insira as informações do aluno\n");
  char nome[50], telefoneEmergencia[12], contatoEmergencia[12];
  short idade;

  printf("Nome: ");
  scanf("%s", &nome);
  printf("Telefone de emergencia: ");
  scanf("%s", &telefoneEmergencia);
  printf("Contato de emergencia: ");
  scanf("%s", &contatoEmergencia);
  printf("Idade: ");
  scanf("%hd", &idade);

  aluno->nome = nome;
  aluno->telefoneEmergencia = telefoneEmergencia;
  aluno->contatoEmergencia = contatoEmergencia;
  aluno->idade = idade;
}

void escreveDadosAluno(ContatoAluno *aluno)
{
  printf("====================================================\n");
  printf("Nome: %s\n", aluno->nome);
  printf("Telefone de emergencia: %s\n", aluno->telefoneEmergencia);
  printf("Contato de emergencia: %s\n", aluno->contatoEmergencia);
  printf("Idade: %hd\n", aluno->idade);
  printf("====================================================\n");
}

int main(int argc, char const *argv[])
{
  short i;
  ContatoAluno contatos[NUM_ALUNOS];

  for (i = 0; i < NUM_ALUNOS; i++)
  {
    lerInfos(&contatos[i]);
  }
  for (i = 0; i < NUM_ALUNOS; i++)
  {
    escreveDadosAluno(&contatos[i]);
  }

  return 0;
}
