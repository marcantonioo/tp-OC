#include "ram.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Ram* iniciaRam(){
    Ram *a = malloc(sizeof(Ram));
    return a;
}

void liberaRam(Ram *a){
    free(a->memoria);
    free(a);
}

Ram* criaRam(Ram *a, int tamanho){
    a->memoria = malloc(tamanho*sizeof(int));
    a->tamanho = tamanho;
    return a;
}

Ram* criaRamVazia(Ram *a, int tamanho){
    Ram *ram = criaRam(a, tamanho);
    for(int i = 0; i<tamanho; i++)
        ram->memoria[i] = 0;
    return ram;
}

Ram* criaRamAleatoria(Ram *a, int tamanho){
    srand(time(NULL));
    Ram *ram = criaRam(ram, tamanho);
    for(int i = 0; i<tamanho; i++)
        ram->memoria[i] = rand();
    return ram;
}

//mecher nas funçoes get dado e set dado depois

void setDado(Ram *ram, int endereco, int conteudo){
    ram->memoria[endereco] = conteudo; 
}

int getDado(Ram *ram, int endereco){
    return ram->memoria[endereco];
}

void imprimir(Ram *ram){
    printf("Conteudo da RAM ");
    for(int i = 0; i<ram->tamanho; i++)
        printf("%d, ",ram->memoria[i]);
    printf("\n");
}