#include <stdio.h>
#include <stdlib.h>

#define MAX 15

typedef struct
{
  int *data;
} Num;
unsigned int ocupados = 0, holder;

Num *lista[MAX];

void inserir(int pos, int value)
{
  if (pos < 0 || pos >= 15)
  {
    printf("Erro: posição fora dos limites");
    return;
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

void visualizar(int pos)
{
  printf("O numero na posição %d é %d", pos, lista[pos]->data);
}

void retirar(int pos)
{
  int next = pos + 1;
  if (ocupados == 0) // The list is empty
  {
    printf("Erro: não há itens para serem removidos da lista");
    return;
  }

  if (lista[pos] != NULL)
  {
    free(lista[pos]);
    lista[pos] = NULL;
    ocupados--;
  }
  if (lista[next] == NULL)
    return;
  lista[pos] = lista[next];
  lista[next] = NULL;
  retirar(next);
}

void exibirLista()
{
  printf("Esta é a representação da lista: \n");
  printf("[ ");
  for (int i = 0; i < MAX; i++)
  {
    if (lista[i] != NULL)
    {
      printf("%d", lista[i]->data);
      if (i < ocupados - 1)
      {
        printf(", ");
      }
    }
  }

  printf(" ]\n");
}

void tamanhoLista()
{
  printf("O número de itens nesta lista é: %d\n", ocupados);
}

int main(int argc, char const *argv[])
{
  short int opcao = 0, i;
  int posicao, valor;

  for (i = 0; i < MAX; i++)
  {
    lista[i] = NULL;
  }

  do
  {
    switch (opcao)
    {
    case 1:
      printf("Inserir na posição: ");
      scanf("%d", &posicao);
      printf("O valor: ");
      scanf("%d", &valor);
      inserir(posicao, valor);
      break;
    case 2:
      printf("Remover da posição: ");
      scanf("%d", &posicao);
      retirar(posicao);
      break;
    case 3:
      printf("Visualizar a posição: ");
      scanf("%d", &posicao);
      visualizar(posicao);
      break;
    case 4:
      exibirLista();
      break;
    case 5:
      tamanhoLista();
      break;
    default:
      printf("Opção não encontrada.\n Terminando o programa.");
      opcao = 0;
      break;
    }
  } while (opcao != 0);

  printf("\n");

  for (i = 0; i < MAX; i++)
    if (lista[i] != NULL)
      free(lista[i]);

  return 0;
}
