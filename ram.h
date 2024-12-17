#ifndef ram_h
#define ram_h
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Ram{
    int *memoria;
    int tamanho;
} Ram;

Ram* iniciaRam();

void liberaRam(Ram *a);

void liberaMemoria(Ram *a);

Ram* criaRam(Ram *a, int tamanho);

Ram* criaRamVazia(Ram *a, int tamanho);

Ram* criaRamAleatoria(Ram *a, int tamanho);

void setDado(Ram *ram, int endereco, int conteudo);

int getDado(Ram *ram, int endereco);

void imprimir(Ram *ram);

#endif