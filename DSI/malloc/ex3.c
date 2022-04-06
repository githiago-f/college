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

#define MAX 3

typedef struct {
    char nome[80];
    char telefone[15];
    char celular[15];
    char endereco[150];
    char aniversario[10];
} Contato;

void inserirContato() {}

void visualizar() {}

int main()
{
    void *opcoes[3] = { "1 - inserir", "2 - visualizar", "3 - sair" };
    int opcao = 0;
    Contato contatos[MAX];

    do {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                inserirContato();
            break;
            case 2:
                visualizar();
            break;
            default:
                opcao = 3;
        }
    } while(opcao != 3);
}
