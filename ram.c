#include "ram.h"

Ram* iniciaRam(){
    Ram *a = malloc(sizeof(Ram));
    a->memoria = NULL;
    return a;
}

void liberaRam(Ram *a){
    if(a->memoria != NULL)
        liberaMemoria(a);
    free(a);
}

void liberaMemoria(Ram *a){
    free(a->memoria);
    a->memoria = NULL;
}

Ram* criaRam(int tamanho){
    Ram *a = malloc(sizeof(Ram));
    a->memoria = NULL;
    a->memoria = malloc(tamanho*sizeof(int));
    a->tamanho = tamanho;
    return a;
}

Ram* criaRamVazia(int tamanho){
    Ram *ram = criaRam(tamanho);
    for(int i = 0; i<tamanho; i++)
        ram->memoria[i] = 0;
    return ram;
}

Ram* criaRamAleatoria(int tamanho){
    srand(time(NULL));
    Ram *ram = criaRam(tamanho);
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
    printf("Conteudo da RAM\n");
    for(int i = 0; i<ram->tamanho; i++)
        printf("%d, ",ram->memoria[i]);
    printf("\n");
}