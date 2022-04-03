#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *matricula;
  char *nome;
  float notas[4];
  int faltas;
} Aluno;

void lerInfosAluno(Aluno *aluno)
{
  char matricula[10], nome[50];
  float notas[4];
  unsigned short faltas;

  printf("====================================================\n");
  printf("Digite a matricula do aluno: ");
  scanf("%s", matricula);
  printf("Digite o nome do aluno: ");
  scanf("%s", nome);
  printf("# Notas \n");
  for (int i = 0; i < 4; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &notas[i]);
  }
  printf("Digite a quantidade de faltas do aluno: ");
  scanf("%hu", &faltas);
  printf("====================================================\n");

  aluno->matricula = matricula;
  aluno->nome = nome;
  aluno->faltas = faltas;
  for (int i = 0; i < 4; i++)
  {
    aluno->notas[i] = notas[i];
  }
}

void escreveInfosAluno(Aluno *aluno)
{
  printf("====================================================\n");
  printf("Matricula: %s\n", aluno->matricula);
  printf("Nome: %s\n", aluno->nome);
  printf("Notas: ");
  for (int i = 0; i < 4; i++)
  {
    printf("%f\n", aluno->notas[i]);
  }
  printf("\n");
  printf("Faltas: %d\n", aluno->faltas);
  printf("====================================================\n");
}

float retornaMedia(Aluno *aluno)
{
  float media = 0;
  for (int i = 0; i < 4; i++)
  {
    media += aluno->notas[i];
  }
  media = media / 4;
  return media;
}

void escreveSituacaoAluno(Aluno *aluno)
{
  float media = retornaMedia(aluno);
  if (media >= 7)
  {
    printf("Aluno aprovado!\n");
    return;
  }
  else if (media >= 5 && media < 7)
  {
    printf("Aluno em recuperação!\n");
    return;
  }
  else
  {
    printf("Aluno reprovado!\n");
    return;
  }
}

int main(int argc, char const *argv[])
{
  Aluno alunos[5];

  for (int i = 0; i < 1; i++)
  {
    lerInfosAluno(&alunos[i]);
  }
  for (int i = 0; i < 1; i++)
  {
    escreveInfosAluno(&alunos[i]);
    printf("\n");
    printf("Media: %f\n", retornaMedia(&alunos[i]));
    printf("====================================================\n");
    escreveSituacaoAluno(&alunos[i]);
  }
  return 0;
}
