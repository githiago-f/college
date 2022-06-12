#include "cpf.h"

int compararCpf(char *c, char *n)
{
  int suma = 0, sumb = 0;
  for (int i = 0; i < 11; i++)
  {
    suma += c[i];
    sumb += n[i];
  }
  return sumb - suma;
}
