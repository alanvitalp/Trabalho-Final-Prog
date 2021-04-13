#include "./vetor.h"

int binSearch(int chave, no *vetor[], int low, int high)
{
  int mid = (low + high) / 2;

  if (chave == vetor[mid]->chave)
    return 1;

  if (chave < vetor[mid]->chave)
  {
    if (mid > low)
      return binSearch(chave, vetor, low, mid - 1);
  }
  else if (chave > vetor[mid]->chave)
  {
    if (mid < high)
      return binSearch(chave, vetor, mid + 1, high);
  }
  return -1;
}

int buscaSequencial(no *vetor[], int tam, int chave)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    if (vetor[i]->chave == chave)
      return 1;
  }
  return -1;
}

int *criar_vetor(int n)
{
  return (int *)malloc(n * sizeof(int));
}

void preencher_vetor(int *v, int n)
{

  srand((unsigned)(time(NULL)));
  for (int i = 0; i < n; i++)
  {
    int random_chave = rand() % RAND_MAX;
    v[i] = random_chave;
  }
}