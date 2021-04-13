#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LISTADUPLA_H
#define LISTADUPLA_H

struct le
{
  int chave;
  double valor;
  struct le *ant;
  struct le *prox;
};

typedef struct le celula;

int inserir_celula(celula **head, celula *nova);

double buscar_valor(int chave, celula *ld);

int buscar_chave(int chave, celula *ld);

int busca_seq(int chave, celula *ld);

void povoa_listaD(celula *head, int qtd_cel);

celula *cria_nova_celula(int chave, double valor);

#endif