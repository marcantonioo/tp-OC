#ifndef CPU_h
#define CPU_h
#include "ram.h"
#include "instrucao.h"

typedef struct CPU {
    int registrador1;
    int registrador2;

    int PC;
    Instrucao *programa;
    int opcode;
} CPU;

CPU* iniciaCPU();

void liberaCPU(CPU *a);

void setPrograma(CPU *cpu, Instrucao *programaAux);

void iniciar(Ram *ram, CPU *cpu);

#endif