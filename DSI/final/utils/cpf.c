#include "cpf.h"

#define CPF_SIZE 11

int compararCpf(char *c, char *n)
{
  int suma = 0, sumb = 0;
  for (int i = 0; i < CPF_SIZE; i++)
  {
    suma += c[i];
    sumb += n[i];
  }
  return sumb - suma;
}
