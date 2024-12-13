#include "CPU.h"

void programaMult(Ram *ram, CPU *cpu, int multiplicando, int multiplicador);

int main(){
    Ram *ram = iniciaRam();
    CPU *cpu = iniciaCPU();

    programaMult(ram, cpu, 2, 4);

    liberaCPU(cpu);
    liberaRam(ram);
    return 0;
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

    int result = getDado(ram, 0);

    printf("O resultado da multiplicação eh: %d\n",result);
}