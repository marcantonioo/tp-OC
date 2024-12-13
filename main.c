#include "CPU.h"

void programaMult(Ram *ram, CPU *cpu, int multiplicando, int multiplicador);
void programaSomaMatriz(Ram *ram, CPU *cpu, int cardinalidade);
int **criaMatriz(int tam);
void liberaMatriz(int **a, int tam);
void programaFat(Ram *ram, CPU *cpu, int fat);
void programaDiv(Ram *ram, CPU *cpu, int dividendo, int divisor);

int main(){
    Ram *ram = iniciaRam();
    CPU *cpu = iniciaCPU();

    //programaMult(ram, cpu, 20, 4);
    //programaSomaMatriz(ram, cpu, 3);
    //programaFat(ram, cpu, 10);
    programaDiv(ram, cpu, 16, 2);

    liberaCPU(cpu);
    liberaRam(ram);
    return 0;
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

    /*endRam = 0;
    printf("Matriz Resultante:\n");
    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){

            printf("%d ",)
        }
    }
    */
    liberaMatriz(matriz1, cardinalidade);
    liberaMatriz(matriz2, cardinalidade);

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