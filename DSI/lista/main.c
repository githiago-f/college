#include <stdio.h>
#include <stdlib.h>

/**
 *
  Você precisa armazenar uma lista de códigos numéricos, a capacidade desta lista é de no máximo 15 posições.
  Os códigos numéricos são todos inteiros (positivos/negativos/zero são aceitos). Os códigos devem ser inseridos conforme informado pelo usuário.
  Seu programa deverá permitir:
  a - Consultar a posição (0 a 14); imprimir o código numérico na tela.
  b - Inserção de um novo elemento na posição indicada pelo usuário;
  Se o usuário indicar uma posição ocupada, os elementos devem "andar" para o final; se foi inserido na posição 5, o 5º deve ser o 6º, 6º deve ser o 7º.... assim sucessivamente.
  se o usuário solicitar a inserção em posição ainda não ocupada, o item deverá ser inserido após a última posição ocupada.
  c - Retirar um elemento indicado pelo usuário; Se houver elementos posteriores, estes devem tomar a posição que ficou livre; se foi removido o 3º elemento, o 4º deve tomar o seu lugar, o 5º deve se tornar 4º e sucessivamente.
  d - Consultar a quantidade de elementos;
  e – exibir todos os itens da lista.

  DIca: ii. armazenar em um número inteiro a quantidade de elementos ocupados; se ocupados é igual a zero, significa que o vetor está vazio, se ocupados é igual a 15 significa que a lista está cheia;

  Para entrega do trabalho:

  1 – Implementar um programa que realize estas operações (a,b,c,d,e);

  2 – Gravar vídeo de 8 a 15 minutos apresentando o código;

  3 – Testar as diferentes possibilidades do programa.

  Não precisa ser uma superprodução, uma chamada meet com o grupo apresentando o código e o programa rodando.

  Enviar o link para o vídeo e o código fonte.
 */

#define MAX 15

typedef struct
{
  int *data;
} Num;
unsigned int ocupados = 0, holder;

Num *lista[MAX];

void inserir(int pos, int value)
{
  if (pos < 0)
  {
    printf("Error: Position is out of bounds");
  }
  int last = pos - 1;
  if (pos > 0 && lista[last] == NULL)
  {
    return inserir(last, value);
  }
  if (lista[pos] == NULL)
  {
    lista[pos] = (Num *)malloc(sizeof(Num));
    lista[pos]->data = value;
    ocupados++;
    return;
  }
  holder = (int)lista[pos]->data;
  lista[pos]->data = value;
  inserir(pos + 1, holder);
}

void visualizar() {}

void retirar()
{
  ocupados--;
}

void exibirLista()
{
  printf("[ ");
  printf("]\n");
}

int main(int argc, char const *argv[])
{
  short int opcao = 0;

  for (int i = 0; i < MAX; i++)
  {
    lista[i] = NULL;
  }

  inserir(3, 1);
  inserir(0, 3);
  inserir(1, 0);

  return 0;
}
