#include <stdio.h>
#include <stdlib.h>

/**
 * Situação Problema:
 *
 * Você precisa armazenar uma lista de códigos numéricos, a capacidade desta lista é de no máximo 20 posições.
 * Os códigos numéricos são todos inteiros positivos.
 * Seu programa deverá permitir:
 * [X] - Consultar a posição (0 a 19); Imprimir o código numérico na tela. (a)
 * [X] - Inserção de um novo elemento na posição indicada pelo usuário; (b)
 * Se o usuário indicar uma posição ocupada, os elementos devem "andar" para o final;
 * [X] - Retirar um elemento indicado pelo usuário; (c)
 * Se houver elementos posteriores, estes devem tomar a posição que ficou livre;
 * [X] - Consultar a quantidade de elementos; (d)
 *
 * Dica:
 * i. Usar um vetor de inteiros de 20 posições;
 * ii. armazenar em um número inteiro a quantidade de elementos ocupados;
 *    se ocupados é  igual a zero, significa que o vetor está vazio,
 *    se ocupados é igual a 20 significa que a lista está cheia;
 *
 * 1 - descrever em Português o processo que deve acontecer em cada um dos itens (a,b,c,d);
 *  a) O programa deverá acessar a posição e imprimir a mesma na tela.
 *  b) O programa deverá guardar o valor que está na posição selecionada,
 *     inserir o novo valor e "mover" o atual para o final da fila recursivamente.
 *  c) O programar deverá assinar a posição selecionada para NULL e verificar se
 *     há valor diferente de NULL na proxima posição, caso haja,
 *     mover o valor para "frente" recursivamente.
 *  d) O programa irá guardar em uma variável o numero de elementos inseridos,
 *     e caso seja removido, irá remover 1 deste valor
 * 2 - descrever quais problemas podem ocorrer nos itens (a,b,c,d); (caso haja);
 *  a) Tentativa de acessar um valor fora dos limites da array pode causar um erro;
 *  b) O Elemento mais ao final do vetor pode ser jogado fora;
 *  c) Caso existam elementos NULL entre os valores do vetor, eles ficarão desagrupados;
 *  d) Uma race-condition onde o valor é acessado várias vezes e acaba perdendo a contagem.
 * 3 - descrever (pelo menos) um caso de teste para cada item (a,b,c,d) que permitam saber se estes estão funcionando adequadamente;
 *  a) Acessar a posição 0 antes de inserir algum valor (deverá retornar 0);
 *  b) Adicionar o valor 1 à posição 0 (deverá imprimir o vetor como: [1, 0, 0...])
 *     Adicionar o valor 2 à posição 0 (deverá imprimir o vetor como: [2, 1, 0...])
 *  c) Após executar o caso de teste B, remover um item na posição 0
 *     (deverá imprimir o vetor como: [1, 0, 0...] novamente)
 *  d) Após executar os dois passos anteriores, ver a quantidade de itens na array
 *     (deverá imprimir 1)
 **/

#define TAMANHO 20

int posicao, counter, i, opcao;
unsigned int *codigo, *holder, quantidadeDeElementos;

unsigned int *CODIGOS[TAMANHO] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL};

void vizualizarVetor()
{
  printf("[");
  for (i = 0; i < TAMANHO; i++)
  {
    printf("%i", (int)CODIGOS[i]);
    if (i != (TAMANHO - 1))
    {
      printf(", ");
    }
  }
  printf("]\n");
  printf("#####################################\n");
}

/**
 * @uses: posicao, CODIGOS
 *
 */
void imprimePosicao()
{
  posicao = 0;
  printf("Imprimir o código na posição (0 até 19): ");
  scanf("%d", &posicao);

  printf("Código nesta posição: %i\n", (int)CODIGOS[posicao]);
}

/**
 * @uses: CODIGOS, holder
 * @param pos
 * @param valor
 */
void moveParaOFinalR(int pos, unsigned int *valor)
{
  holder = CODIGOS[pos];
  CODIGOS[pos] = valor;
  if (holder != (unsigned int *)NULL && pos != TAMANHO - 1)
  {
    moveParaOFinalR(pos + 1, holder);
  }
}

void moveParaFrenteR(int pos)
{
  if (CODIGOS[pos + 1] == NULL)
  {
    return;
  }
  CODIGOS[pos] = CODIGOS[pos + 1];
  CODIGOS[pos + 1] = NULL;
  return moveParaFrenteR(pos + 1);
}

/**
 * @uses: posicao, codigo, holder, CODIGOS
 */
void inserirCodigoNaPosicao()
{
  posicao = 0, codigo = 0;
  printf("Inserir o código: ");
  scanf("%d", (int *)&codigo);
  printf("Na posição (0 até 19): ");
  scanf("%d", &posicao);
  moveParaOFinalR(posicao, codigo);
  vizualizarVetor();
  quantidadeDeElementos++;
}

/**
 * @uses: posicao, TAMANHO, CODIGOS
 */
void retirarElementoNaPosicao()
{
  posicao = 0;
  printf("Retirar elemento na posição: ");
  scanf("%d", &posicao);
  if (posicao < 0 || posicao > TAMANHO)
  {
    printf("Erro: posição está fora dos limites do vetor");
  }
  CODIGOS[posicao] = NULL;
  moveParaFrenteR(posicao);
  vizualizarVetor();
  quantidadeDeElementos--;
}

/**
 * @uses: quantidadeDeElementos
 */
void imprimeQuantidadeDeElementos()
{
  printf("%i\n", quantidadeDeElementos);
  printf("#####################################\n");
}

int main()
{
  do
  {
    printf("O que deseja fazer?\n");
    printf("1 - Vizualizar o vetor\n");
    printf("2 - Consultar valor na posição\n");
    printf("3 - Inserir um valor na posição\n");
    printf("4 - Remover o valor na posição\n");
    printf("5 - Vizualizar contagem de elementos\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    printf("#####################################\n");
    switch (opcao)
    {
    case 1:
      vizualizarVetor();
      break;
    case 2:
      imprimePosicao();
      break;
    case 3:
      inserirCodigoNaPosicao();
      break;
    case 4:
      retirarElementoNaPosicao();
      break;
    case 5:
      imprimeQuantidadeDeElementos();
    default:
      break;
    }
  } while (opcao != 0);
  return 0;
}
