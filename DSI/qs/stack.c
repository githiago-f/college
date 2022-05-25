#include <stdio.h>

#define MAX 10

const int FIM = 9, INICIO = 0;

unsigned int topo = 0;

int push(int stack[], int valor)
{
  if (topo == FIM)
    return 0;
  stack[topo] = valor;
  topo++;
  return 1;
}

int pop(int stack[], int *status)
{
  if (topo == INICIO - 1)
    (*status) = 0;
  else
  {
    int valor = stack[topo - 1];
    topo--;
    (*status) = 1;
    return valor;
  }
}

void repeat(int stack[], int *status)
{
  int a = pop(stack, status);
  int b = pop(stack, status);

  push(stack, a / b);
}

int main(int argc, char const *argv[])
{
  int stack[MAX];
  int *status;

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  push(stack, 6);
  push(stack, 7);

  repeat(stack, status);
  repeat(stack, status);
  repeat(stack, status);
  repeat(stack, status);
  repeat(stack, status);
  repeat(stack, status);
  repeat(stack, status);

  return 0;
}
