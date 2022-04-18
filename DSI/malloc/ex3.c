#include <stdio.h>
#include <stdlib.h>

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
    char *opcoes[3] = {
        "1 - inserir",
        "2 - visualizar",
        "3 - sair"};
    int opcao = 0, i = 0, position = 0, a = 0;
    Contato *contatos[MAX];

    for(int x = 0; x<MAX; x++)
        contatos[x] = NULL;

    do {
        for (a = 0; a < 3; a++)
        {
            printf("%s\n", opcoes[a]);
        }
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                contatos[i] = (Contato *)malloc(sizeof(Contato));
                if(contatos[i] == 0) {
                    printf("ih mané");
                    return 1;
                }
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
    for (a = 0; a < i; a++)
        if (contatos[a] != 0)
            free(contatos[a]);
}
