#include "./listaDupla.h"

celula *cria_celula_aleatoria()
{
  celula *novo;
  novo = malloc(sizeof(celula));

  int random_chave = rand() % RAND_MAX;
  double random_double = (float)rand() / RAND_MAX;

  novo->chave = random_chave;
  novo->valor = random_double;
  novo->ant = NULL;
  novo->prox = NULL;
  return novo;
}

celula *cria_nova_celula(int chave, double valor)
{
  celula *novo;
  novo = malloc(sizeof(celula));
  novo->chave = chave;
  novo->valor = valor;
  novo->ant = NULL;
  novo->prox = NULL;
  return novo;
}

int inserir_celula(celula **head, celula *nova_celula)
{
  celula **aux;

  if (*head == NULL)
  {
    *head = nova_celula;
    return 0;
  }
  if (*head != NULL)
  {
    aux = head;
    while ((*aux)->prox != NULL)
    {
      if ((*aux)->chave == nova_celula->chave)
      {
        free(nova_celula);
        return -1;
      }
      aux = &((*aux)->prox);
    }

    if ((*aux)->chave == nova_celula->chave)
    {
      free(nova_celula);
      return -1;
    }

    (*aux)->prox = nova_celula;
    nova_celula->ant = (*aux);
    return 0;
  }
}

double buscar_valor(int chave, celula *ld)
{
  if (ld == NULL)
    return -1;
  if (ld->chave == chave)
    return ld->valor;
  return buscar_valor(chave, ld->prox);
}

int buscar_chave(int chave, celula *ld)
{
  if (ld == NULL)
    return -1;
  if (ld->chave == chave)
    return 1;
  return buscar_chave(chave, ld->prox);
}

int busca_seq(int chave, celula *ld)
{
  while (ld->prox != NULL && ld->chave != chave)
  {
    ld = ld->prox;
  }
  if (ld->chave == chave)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void povoa_listaD(celula *head, int qtd_cel)
{
  for (int i = 0; i < qtd_cel; i++)
  {
    celula *nova = cria_celula_aleatoria();

    srand((unsigned)time(NULL));
    while (inserir_celula(&head, nova) != 0)
    {
      nova = cria_celula_aleatoria();
    }
  }
}