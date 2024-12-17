#ifndef programas_h
#define programas_h

#include "CPU.h"

void programaMult(Ram *ram, CPU *cpu, int multiplicando, int multiplicador);

void programaSomaMatriz(Ram *ram, CPU *cpu, int cardinalidade);
int **criaMatriz(int tam);
void liberaMatriz(int **a, int tam);

void programaFat(Ram *ram, CPU *cpu, int fat);

void programaDiv(Ram *ram, CPU *cpu, int dividendo, int divisor);

void programaFatorialDuplo(Ram *ram, CPU *cpu, int n);

void programaPA(Ram *ram, CPU *cpu, int primeiroTermo, int razao, int numTermos);

void programaFibonacci(Ram *ram, CPU *cpu, int n);

void programaExpo(Ram *ram, CPU *cpu, int base, int expoente);

void programaSoma(Ram *ram, CPU *cpu, int x, int y);

void programaSub(Ram *ram, CPU *cpu, int x, int y);

#endif