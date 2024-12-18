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

Ram* criaRam(int tamanho);

Ram* criaRamVazia(int tamanho);

Ram* criaRamAleatoria(int tamanho);

void setDado(Ram *ram, int endereco, int conteudo);

int getDado(Ram *ram, int endereco);

void imprimir(Ram *ram);

#endif