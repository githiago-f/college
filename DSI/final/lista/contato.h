typedef struct
{
  char nome[80];
  char cpf[11];
  char email[80];
} Contato;

Contato *novoContato();
void imprimeContato(Contato *contato);
