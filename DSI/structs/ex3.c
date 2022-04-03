#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *matricula;
  char *nome;
  float notas[4];
  int faltas;
} Aluno;

Aluno alunos[5];

void lerInfosAluno(int indice)
{
  printf("====================================================\n");
  char matricula[10], nome[50];
  float notas[4];
  int faltas;

  printf("Digite a matricula do aluno: ");
  scanf("%s", &matricula);
  printf("Digite o nome do aluno: ");
  scanf("%s", &nome);
  printf("# Notas \n");
  for (int i = 0; i < 4; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &notas[i]);
  }
  printf("Digite a quantidade de faltas do aluno: ");
  scanf("%d", &faltas);
  printf("====================================================\n");

  alunos[indice].matricula = matricula;
  alunos[indice].nome = nome;
  for (int i = 0; i < 4; i++)
  {
    alunos[indice].notas[i] = notas[i];
  }
  alunos[indice].faltas = faltas;
}

void escreveInfosAluno(int indice)
{
  printf("====================================================\n");
  printf("Matricula: %s\n", alunos[indice].matricula);
  printf("Nome: %s\n", alunos[indice].nome);
  printf("Notas: ");
  for (int i = 0; i < 4; i++)
  {
    printf("%f\n", alunos[indice].notas[i]);
  }
  printf("\n");
  printf("Faltas: %d\n", alunos[indice].faltas);
  printf("====================================================\n");
}

float mediaAluno(int indice)
{
  float media = 0;
  for (int i = 0; i < 4; i++)
  {
    media += alunos[indice].notas[i];
  }
  media = media / 4;
  return media;
}

void imprimeSituacaoAluno(int indice)
{
  float media = mediaAluno(indice);
  if (media >= 7)
  {
    printf("Aluno aprovado\n");
  }
  else if (media >= 5 && media < 7)
  {
    printf("Aluno em recuperacao\n");
  }
  else
  {
    printf("Aluno reprovado\n");
  }
}

int main(int argc, char const *argv[])
{
  const int size = 5;
  for (int i = 0; i < size; i++)
  {
    lerInfosAluno(i);
  }
  for (int i = 0; i < size; i++)
  {
    escreveInfosAluno(i);
    printf("Media: %f\n", mediaAluno(i));
  }
  for (int i = 0; i < size; i++)
  {
    imprimeSituacaoAluno(i);
  }
  return 0;
}
