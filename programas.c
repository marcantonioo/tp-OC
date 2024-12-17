#include "programas.h"

void programaSub(Ram *ram, CPU *cpu, int x, int y){

    criaRamVazia(ram,2);

    Instrucao *trecho1 = malloc(6*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, x, -1);
    trecho1[1] = defineInstrucao(4, 2, y, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(1, 0, 1, 0);
    trecho1[5] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram ,cpu);

    printf("O resultado de %d - %d é: %d\n", x, y, cpu->registrador1);
}

void programaSoma(Ram *ram, CPU *cpu, int x, int y){

    criaRamVazia(ram,2);

    Instrucao *trecho1 = malloc(6*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, x, -1);
    trecho1[1] = defineInstrucao(4, 2, y, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(0, 0, 1, 0);
    trecho1[5] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram ,cpu);

    printf("O resultado de %d + %d é: %d\n", x, y, cpu->registrador1);
}



void programaExpo(Ram *ram, CPU *cpu, int base, int expoente) {

    criaRamVazia(ram, 2);

    Instrucao *trecho1 = malloc(5*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, base, -1);
    trecho1[1] = defineInstrucao(4, 2, base, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    liberaMemoria(ram);

    for(int i = expoente-1; i>0; i--){
        programaMult(ram, cpu, cpu->registrador1, base);
        Instrucao *trecho2 = malloc(2*sizeof(Instrucao));
        trecho2[0] = defineInstrucao(4, 2, base, -1);
        trecho2[1] = defineInstrucao(-1, -1, -1, -1);

        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);

        liberaMemoria(ram); 
    }


    printf("O valor da exponenciação é: %d\n", cpu->registrador1);
}



void programaFibonacci(Ram *ram, CPU *cpu, int n) {

    criaRamVazia(ram, 2); 

    Instrucao *inicializa = malloc(5 * sizeof(Instrucao));
    inicializa[0] = defineInstrucao(4, 1, 0, -1);
    inicializa[1] = defineInstrucao(4, 2, 1, -1); 
    inicializa[2] = defineInstrucao(2, 1, 0, -1);
    inicializa[3] = defineInstrucao(2, 2, 1, -1);
    inicializa[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, inicializa);
    iniciar(ram, cpu);

    for (int i = 2; i <= n; i++) {
        Instrucao *passo = malloc(6 * sizeof(Instrucao));
        passo[0] = defineInstrucao(0, 0, 1, 0);
        passo[1] = defineInstrucao(3, 2, 0, -1);
        passo[2] = defineInstrucao(3, 1, 1, -1);
        passo[3] = defineInstrucao(2, 2, 1, -1);
        passo[4] = defineInstrucao(2, 1, 0, -1);
        passo[5] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, passo);
        iniciar(ram, cpu);
    }

    printf("O %d-ésimo número de Fibonacci é: %d\n", n, cpu->registrador2);

    liberaMemoria(ram);
}





void programaPA(Ram *ram, CPU *cpu, int primeiroTermo, int razao, int numTermos) {
    criaRamVazia(ram, 2);

    Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
    

    trecho1[0] = defineInstrucao(4, 1, primeiroTermo, -1);
    trecho1[1] = defineInstrucao(2, 1, 0, -1);
    trecho1[2] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);


    for (int i = 1; i < numTermos; i++) {
        Instrucao *trecho2 = malloc(6 * sizeof(Instrucao));
        trecho2[0] = defineInstrucao(3, 1, 0, -1);
        trecho2[1] = defineInstrucao(4, 2, razao, -1);
        trecho2[2] = defineInstrucao(2, 2, 1, -1);
        trecho2[3] = defineInstrucao(0, 0, 1, 1);
        trecho2[4] = defineInstrucao(2, 1, 0, -1);
        trecho2[5] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);
    }

    printf("O último termo da PA é: %d\n", cpu->registrador1);

    liberaMemoria(ram);
}




void programaFatorialDuplo(Ram *ram, CPU *cpu, int n) {
    criaRamVazia(ram, 2);


    Instrucao *inicializa = malloc(2 * sizeof(Instrucao));
    inicializa[0] = defineInstrucao(4, 2, 1, -1);
    inicializa[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, inicializa);
    iniciar(ram, cpu);

    liberaMemoria(ram);
    
    while (n > 0) {
    
        programaMult(ram, cpu, cpu->registrador2, n);

        Instrucao *atualizaAcumulador = malloc(3 * sizeof(Instrucao));
        atualizaAcumulador[0] = defineInstrucao(2, 1, 0, -1);
        atualizaAcumulador[1] = defineInstrucao(3, 2, 0, -1);
        atualizaAcumulador[2] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, atualizaAcumulador);
        iniciar(ram, cpu);

        liberaMemoria(ram);

        n -= 2;
    }

    printf("O resultado do fatorial duplo eh: %d\n", cpu->registrador2);

}




int **criaMatriz(int tam){
    int **matriz = malloc(tam * sizeof(int*));
    for(int i = 0; i<tam; i++){
        matriz[i] = malloc(tam * sizeof(int));
    }
    return matriz;
}



void liberaMatriz(int **a, int tam){
    for(int i = 0; i<tam; i++){
        free(a[i]);
    }
    free(a);
}



void programaDiv(Ram *ram, CPU *cpu, int dividendo, int divisor){
    criaRamVazia(ram, 4);

    Instrucao *trecho1 = malloc(5 * sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, dividendo, -1);
    trecho1[1] = defineInstrucao(2, 1, 0, -1);
    trecho1[2] = defineInstrucao(4, 2, divisor, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);


    Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
    trecho2[0] = defineInstrucao(4, 1, 1, -1);
    trecho2[1] = defineInstrucao(2, 1, 2, -1);
    trecho2[2] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);

    while(dividendo>=divisor){
        Instrucao *trecho3 = malloc(5 * sizeof(Instrucao));
        trecho3[0] = defineInstrucao(1, 0, 1, 0);
        trecho3[1] = defineInstrucao(0, 2, 3, 3);
        trecho3[2] = defineInstrucao(3, 1, 0, -1);
        trecho3[3] = defineInstrucao(5, 1, -1, -1);
        trecho3[4] = defineInstrucao(-1, -1, -1, -1);

        setPrograma(cpu, trecho3);
        iniciar(ram, cpu);

        dividendo = cpu->registrador1;
    }

    Instrucao *trecho4 = malloc(3 * sizeof(Instrucao));
    trecho4[0] = defineInstrucao(3, 1, 3, -1);
    trecho4[1] = defineInstrucao(5, 1, -1, -1);
    trecho4[2] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho4);
    iniciar(ram, cpu);

    printf("O resultado da divisão eh: %d\n", cpu->registrador1);

    liberaMemoria(ram);
}



void programaFat(Ram *ram, CPU *cpu, int fat){
    int j = 1;

    for(int i = 1; i<=fat; i++){
        programaMult(ram, cpu, j, i);

        Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
        Instrucao inst0 = defineInstrucao(3, 1, 0, -1);
        trecho1[0] = inst0;

        Instrucao inst2 = defineInstrucao(5, 1, -1, -1);
        trecho1[1] = inst2;

        Instrucao inst3 = defineInstrucao(-1, -1, -1, -1);
        trecho1[2] = inst3;

        setPrograma(cpu, trecho1);
        iniciar(ram, cpu);

        j = cpu->registrador1;
        if(i != fat)
            liberaMemoria(ram);
    }

    Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
    Instrucao inst4 = defineInstrucao(3, 1, 0, -1);
    trecho2[0] = inst4;

    Instrucao inst5 = defineInstrucao(5, 1, -1, -1);
    trecho2[1] = inst5;

    Instrucao inst6 = defineInstrucao(-1, -1, -1, -1);
    trecho2[2] = inst6;

    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);

    printf("O resultado do fatorial eh: %d\n", cpu->registrador1);
    liberaMemoria(ram);
}



void programaSomaMatriz(Ram *ram, CPU *cpu, int cardinalidade){
    int **matriz1 = criaMatriz(cardinalidade);
    int **matriz2 = criaMatriz(cardinalidade);
    srand(time(NULL));
    
    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            matriz1[i][j] = rand() % 100;
            matriz2[i][j] = rand() % 100;
        }
    }

    criaRamVazia(ram, 27);
    int endRam = 0;

    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
            Instrucao inst0 = defineInstrucao(4, 1, matriz1[i][j], -1);
            trecho1[0] = inst0;

            Instrucao inst1 = defineInstrucao(2, 1, endRam, -1);
            trecho1[1] = inst1;

            Instrucao inst3 = defineInstrucao(-1, -1, -1, -1);
            trecho1[2] = inst3;

            setPrograma(cpu, trecho1);
            iniciar(ram, cpu);

            endRam++;
        }
    }


    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
            Instrucao inst0 = defineInstrucao(4, 1, matriz2[i][j], -1);
            trecho2[0] = inst0;

            Instrucao inst1 = defineInstrucao(2, 1, endRam, -1);
            trecho2[1] = inst1;

            Instrucao inst3 = defineInstrucao(-1, -1, -1, -1);
            trecho2[2] = inst3;

            setPrograma(cpu, trecho2);
            iniciar(ram, cpu);

            endRam++;
        }
    }

    endRam = 0;
    int delta = 9;

    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho3 = malloc(2*sizeof(Instrucao));
            Instrucao inst1 = defineInstrucao(0, endRam, endRam+delta, endRam+(2*delta));
            trecho3[0] = inst1;

            Instrucao inst2 = defineInstrucao(-1, -1, -1, -1);
            trecho3[1] = inst2;

            setPrograma(cpu, trecho3);
            iniciar(ram, cpu);

            endRam++;
        }
    }

    liberaMatriz(matriz1, cardinalidade);
    liberaMatriz(matriz2, cardinalidade);
    liberaMemoria(ram);

}



void programaMult(Ram *ram, CPU *cpu, int multiplicando, int multiplicador){
    
    criaRamVazia(ram, 2);
    
    Instrucao *trecho1 = malloc(3*sizeof(Instrucao));
    Instrucao inst0 = defineInstrucao(4, 1, multiplicando, -1);
    trecho1[0] = inst0;

    Instrucao inst1 = defineInstrucao(2, 1, 1, -1);
    trecho1[1] = inst1;

    Instrucao inst2 = defineInstrucao(-1, -1, -1, -1);
    trecho1[2] = inst2;

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    for(int i = 0; i<multiplicador; i++){
        Instrucao *trecho2 = malloc(2*sizeof(Instrucao));
        Instrucao inst3 = defineInstrucao(0, 0, 1, 0);
        trecho2[0] = inst3;

        Instrucao inst4 = defineInstrucao(-1, -1, -1, -1);
        trecho2[1] = inst4;

        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);

    }

    Instrucao *trecho3 = malloc(3 * sizeof(Instrucao));
    Instrucao inst5 = defineInstrucao(3, 1, 0, -1);
    trecho3[0] = inst5;

    Instrucao inst6 = defineInstrucao(5, 1, -1, -1);
    trecho3[1] = inst6;

    Instrucao inst7 = defineInstrucao(-1, -1, -1, -1);
    trecho3[2] = inst7;

    setPrograma(cpu, trecho3);
    iniciar(ram, cpu);

    printf("O resultado da multiplicação eh: %d\n",cpu->registrador1);

}