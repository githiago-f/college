#include <stdio.h>
#include <stdlib.h>

/**
Criar agenda:
Cada registro deve ter capacidade para armazenar o nome, telefone, celular, endereço e aniversário.
A agenda deve ser apresentar as opções: 
1- inserir / 2-visualizar os dados de uma posição (perguntar a posição) / 3-sair; (ficar em laço até o usuário escolher sair). 
Máximo de 100 registros. (criar vetor de 100 posições, cada posição é um ponteiro para contato).
Cada contato é criado dinamicamente ocupando as posições no vetor sequencialmente.
Não esqueça de liberar a memória no final do programa, antes de sair.
*/

#define MAX 100

typedef struct {
    char nome[80];
    char telefone[15];
    char celular[15];
    char endereco[150];
    char aniversario[10];
} Contato;

void inserirContato(Contato *contato)
{
    printf("Digite o nome: ");
    scanf("%s", contato->nome);
    printf("Digite o telefone: ");
    scanf("%s", contato->telefone);
    printf("Digite o celular: ");
    scanf("%s", contato->celular);
    printf("Digite o endereco: ");
    scanf("%s", contato->endereco);
    printf("Digite o aniversario: ");
    scanf("%s", (*contato).aniversario);
}

void visualizar(Contato *contato)
{
    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %s\n", contato->telefone);
    printf("Celular: %s\n", contato->celular);
    printf("Endereco: %s\n", contato->endereco);
    printf("Aniversario: %s\n", contato->aniversario);
}

int main()
{
    void *opcoes[3] = {
        "1 - inserir",
        "2 - visualizar",
        "3 - sair"};
    int opcao = 0, i = 0, position = 0, a = 0;
    Contato *contatos[MAX];

    do {
        for (a = 0; a < 3; a++)
        {
            printf("%s\n", opcoes[a]);
        }
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                contatos[i] = (Contato *)malloc(sizeof(Contato));
                inserirContato(contatos[i]);
                i++;
                printf("Adicionado com sucesso!\n");
                break;
            case 2:
                printf("Digite a posicao: ");
                scanf("%d", &position);
                visualizar(contatos[position]);
                break;
            default:
                opcao = 3;
        }
    } while(opcao != 3);
    for (a = 0; a < MAX; a++)
        if (contatos[a] != 0)
            free(contatos[a]);
}
