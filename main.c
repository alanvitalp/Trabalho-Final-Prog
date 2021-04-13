#include <stdlib.h>
#include <stdio.h>
#include "./abb.h"
#include "./listaDupla.h"
#include "./vetor.h"
#include "./config.h"
#include <time.h>

void percorrer_arvore(no *raiz, no *vetor[], int *posicao)
{

  if (raiz == NULL)
  {
    // printf("RAIZ NULA!");
    return;
  }

  if (raiz != NULL)
  {
    percorrer_arvore(raiz->esq, vetor, posicao);
    vetor[*posicao] = raiz;
    (*posicao)++;
    percorrer_arvore(raiz->dir, vetor, posicao);
  }
}

int main(void)
{

  clock_t t;

  no *v[n];
  no *raiz = NULL;
  celula *head = NULL;
  int *x = malloc(sizeof(int));
  *x = 0;
  int chave;
  int opcao;

  povoa_arvore(&raiz, n);

  percorrer_arvore(raiz, v, x);

  povoa_listaD(head, n);

  while (opcao != 5)
  {

    printf("\n1 - Busca em ABB\n");
    printf("2 - Busca Binária em Vetor\n");
    printf("3 - Busca sequencial em Vetor\n");
    printf("4 - Busca sequencial em Lista Duplamente Encadeada\n");
    printf("5 - Sair\n");

    printf("\nDigite sua escolha: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("\n\nDigite o valor da chave: ");
      scanf("%d", &chave);

      t = clock();
      for (int i = 0; i < k; i++)
      {
        busca_no(raiz, chave);
      }
      t = clock() - t;

      printf("Existe chave: %d\n", existe_chave(raiz, chave));

      printf("Tempo de execucao das K buscas: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
      break;

    case 2:
      printf("\nDigite o valor da chave: ");
      scanf("%d", &chave);

      t = clock();
      for (int i = 0; i < k; i++)
      {
        binSearch(chave, v, 0, n);
      }
      t = clock() - t;

      printf("Existe chave: %d\n", binSearch(chave, v, 0, n));

      printf("Tempo de execucao das K buscas: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
      break;

    case 3:
      printf("\nDigite o valor da chave: ");
      scanf("%d", &chave);

      t = clock();
      for (int i = 0; i < k; i++)
      {
        buscaSequencial(v, n, chave);
      }
      t = clock() - t;

      printf("Existe chave: %d\n", buscaSequencial(v, n, chave));

      printf("Tempo de execucao das K buscas: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
      break;
    case 4:
      printf("\nDigite o valor da chave: ");
      scanf("%d", &chave);

      t = clock();

      for (int i = 0; i < k; i++)
      {
        busca_seq(chave, head);
      }
      t = clock() - t;

      printf("Existe chave: %d\n", busca_seq(chave, head));

      printf("Tempo de execucao das K buscas: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));

    default:
      break;
    }
  }

  return EXIT_SUCCESS;
}