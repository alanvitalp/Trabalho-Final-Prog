#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef ABB_H
#define ABB_H

typedef struct reg
{
  int chave;
  double valor;
  struct reg *esq, *dir;
} no;

no *criar_no_aleatorio();

no *criar_no_arbitrario(int chave, double valor);

int inserir_no(no **raiz, no *novo);

no *busca_no(no *raiz, int chave);

int existe_chave(no *raiz, int chave);

double busca_valor(no *raiz, int chave);

void povoa_arvore(no **raiz, int qtd_no);

void desalocar_arvore(no *raiz);

#endif