#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./abb.h"

#ifndef VETOR_H
#define VETOR_H

int binSearch(int val, no *vetor[], int fim, int valor);

int buscaSequencial(no *vetor[], int tamanho, int valor);

int *criar_vetor(int n);

void preencher_vetor(int *v, int n);

#endif