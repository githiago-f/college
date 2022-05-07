#include <stdio.h>

#define MAX 16

int tamanho = 0;

void inserir(int lista[], int valor, int pos)
{
  if (pos >= tamanho)
  {
    lista[tamanho] = valor;
    if (tamanho < MAX - 1)
    {
      tamanho++;
    }
    return;
  }
  int holder = lista[pos];
  lista[pos] = valor;
  inserir(lista, holder, pos + 1);
}

void swapBack(int lista[], int pos1, int pos2)
{
  int holder = lista[pos1];
  lista[pos1] = lista[pos2];
  lista[pos2] = holder;
}

void remover(int lista[], int posicao)
{
  if (tamanho <= 0)
  {
    printf("Lista vazia\n");
    return;
  }
  if (posicao >= tamanho)
  {
    printf("Posição não ocupada\n");
    return;
  }
  tamanho--;
  for (int i = posicao; i < tamanho; i++)
  {
    swapBack(lista, i, i + 1);
  }
}

void printTamanho()
{
  printf("Ocupados: %d\n", tamanho);
}

void printPosicao(int lista[], int posicao)
{
  if (posicao < 0 || posicao >= tamanho)
  {
    printf("Fora dos limites da lista\n");
    return;
  }
  printf("O numero na posicao %d da lista é %d\n", posicao, lista[posicao]);
}

void mostrarLista(int lista[])
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", lista[i]);
  }
  printf("\n");
}

void demo(int lista[])
{
  printf("### Demonstração ###\n");
  // enche a lista
  for (int i = 0; i < MAX; i++)
  {
    inserir(lista, i, 0);
  }
  mostrarLista(lista);
  printTamanho();

  inserir(lista, 40, 4);
  mostrarLista(lista);
  printTamanho();

  inserir(lista, 500, 0);
  mostrarLista(lista);
  printTamanho();

  // esvazia a lista
  while (tamanho > 0)
  {
    remover(lista, 0);
  }
  printf("Após remover todos os itens: \n");
  printf("Lista atual: ");
  mostrarLista(lista);
  printTamanho();

  printf("### Fim da demonstração ###\n");
}

int main(int argc, char const *argv[])
{
  int lista[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  demo(lista);
  int valor, posicao;
  char operacao;

  do
  {
    valor = 0, posicao = 0;
    printf("Que operação deseja fazer?\n");

    printf("a - consultar a posição\n");
    printf("b - inserir elemento\n");
    printf("c - retirar elemento\n");
    printf("d - ver quantidade de elementos na lista\n");
    printf("e - exibir itens na lista\n");
    printf("f - fechar o programa\n");

    scanf(" %c", &operacao);

    switch (operacao)
    {
    case 'a':
      printf("Que posição?");
      scanf("%d", &posicao);
      printPosicao(lista, posicao);
      break;
    case 'b':
      printf("Em que posição?");
      scanf("%d", &posicao);
      printf("Qual o valor?");
      scanf("%d", &valor);
      inserir(lista, valor, posicao);
      break;
    case 'c':
      printf("De que posição?");
      scanf("%d", &posicao);
      remover(lista, posicao);
      break;
    case 'd':
      printTamanho();
      break;
    case 'e':
      mostrarLista(lista);
      break;
    default:
      operacao = 'f';
      printf("Operação inválida, saindo...\n\n\n\n");
      break;
    }
  } while (operacao != 'f');

  return 0;
}
