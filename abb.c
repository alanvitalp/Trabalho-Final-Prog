#include "./abb.h"

no *criar_no_aleatorio()
{
  int random_chave = rand() % RAND_MAX;
  double random_double = (float)rand() / RAND_MAX;

  return criar_no_arbitrario(random_chave, random_double);
}

no *criar_no_arbitrario(int chave, double valor)
{
  no *novo;
  novo = malloc(sizeof(no));
  novo->chave = chave;
  novo->valor = valor;
  novo->esq = novo->dir = NULL;

  return novo;
}

int inserir_no(no **raiz, no *novo)
{
  if (*raiz == NULL)
  {
    *raiz = novo;
    return 0;
  }
  if ((*raiz)->chave > novo->chave)
  {
    return inserir_no(&((*raiz)->esq), novo);
  }
  else if ((*raiz)->chave < novo->chave)
  {
    return inserir_no(&((*raiz)->dir), novo);
  }
  else
  {
    return 1; // no com essa chave já existe
  }
  return 0;
}

no *busca_no(no *raiz, int chave)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (raiz->chave > chave)
  {
    return busca_no(raiz->esq, chave);
  }
  else if (raiz->chave < chave)
  {
    return busca_no(raiz->dir, chave);
  }
  else
  {
    return raiz;
  }
}

int existe_chave(no *raiz, int chave)
{
  return raiz != NULL && (busca_no(raiz, chave) != NULL);
}

double busca_valor(no *raiz, int chave)
{
  no *no_resultado;
  no_resultado = busca_no(raiz, chave);
  if (no_resultado != NULL)
  {
    return no_resultado->valor;
  }
  else
  {
    return -1;
  }
}

void povoa_arvore(no **raiz, int qtd_no)
{
  for (int i = 0; i < qtd_no; i++)
  {
    no *novo = criar_no_aleatorio();

    srand((unsigned)time(NULL));
    while (inserir_no(raiz, novo) != 0)
    {
      free(novo);
      novo = criar_no_aleatorio();
    }
  }
}

void desalocar_arvore(no *raiz)
{
  if (raiz != NULL)
  {
    desalocar_arvore(raiz->esq);
    desalocar_arvore(raiz->dir);
    free(raiz);
  }
}