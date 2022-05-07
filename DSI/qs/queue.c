#include <stdio.h>

#define MAX 10

typedef struct
{
  int vet[MAX];
  int inicio;
  int fim;
} SeqFila;

void criar(SeqFila *f)
{
  f->inicio = -1;
  f->fim = -1;
}

int cheia(SeqFila *f)
{
  return f->fim == MAX - 1;
}

int vazia(SeqFila *f)
{
  return (f->fim < f->inicio);
}

void inserir(int value, SeqFila *f)
{
  if (cheia(f))
  {
    return;
  }

  if (f->fim == f->inicio)
  {
    f->inicio = 0;
  }

  f->fim++;
  f->vet[f->fim] = value;
}

int remover(SeqFila *f)
{
  if (vazia(f))
  {
    return 0;
  }
  f->inicio++;
  return f->vet[f->inicio];
}

void imprimeFila(SeqFila *f)
{
  printf("[");
  for (int i = f->inicio; i < f->fim; i++)
    printf("%d, ", f->vet[i]);
  printf("]\n");
}

int main(int argc, char const *argv[])
{
  SeqFila fila;

  criar(&fila);

  inserir(1, &fila);
  imprimeFila(&fila);
  inserir(2, &fila);
  imprimeFila(&fila);
  inserir(3, &fila);
  inserir(4, &fila);
  inserir(5, &fila);
  inserir(6, &fila);
  inserir(7, &fila);
  inserir(8, &fila);
  inserir(9, &fila);
  inserir(10, &fila);
  imprimeFila(&fila); // imprime [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ]

  remover(&fila);
  imprimeFila(&fila);
  remover(&fila);
  imprimeFila(&fila);
  remover(&fila);
  imprimeFila(&fila); // imprime [4, 5, 6, 7, 8, 9, 10, ]

  return 0;
}
